package cmd

import (
	"add/internal/config"
	"add/internal/handler"
	"add/internal/middleware"
	"add/internal/svc"
	"os"

	"github.com/common-nighthawk/go-figure"
	"github.com/jzero-io/jzero-contrib/swaggerv2"
	"github.com/spf13/cobra"
	"github.com/zeromicro/go-zero/core/conf"
	"github.com/zeromicro/go-zero/core/logx"
	"github.com/zeromicro/go-zero/core/proc"
	"github.com/zeromicro/go-zero/core/service"
	"github.com/zeromicro/go-zero/rest"
	"golang.org/x/sync/errgroup"
)

// serverCmd represents the server command
var serverCmd = &cobra.Command{
	Use:   "server",
	Short: "add server",
	Long:  "add server",
	Run: func(cmd *cobra.Command, args []string) {
		Start(cfgFile)
	},
}

func Start(cfgFile string) {
	var c config.Config
	conf.MustLoad(cfgFile, &c)
	config.C = c

	// set up logger
	if err := logx.SetUp(c.Log.LogConf); err != nil {
		logx.Must(err)
	}
	if c.Log.LogConf.Mode != "console" {
		logx.AddWriter(logx.NewWriter(os.Stdout))
	}

	ctx := svc.NewServiceContext(c)
	start(ctx)
}

func start(svcCtx *svc.ServiceContext) {
	server := rest.MustNewServer(svcCtx.Config.Rest.RestConf)
	middleware.RegisterMiddlewares(server)

	// server add api handlers
	handler.RegisterHandlers(server, svcCtx)

	// server add swagger routes. If you do not want it, you can delete this line
	swaggerv2.RegisterRoutes(server)

	// server add routes
	// You can use server.AddRoutes() to add your own handler

	group := service.NewServiceGroup()
	group.Add(server)

	// shutdown listener
	wailExit := proc.AddShutdownListener(svcCtx.Custom.Stop)

	eg := errgroup.Group{}
	eg.Go(func() error {
		printBanner(svcCtx.Config)
		logx.Infof("Starting rest server at %s:%d...", svcCtx.Config.Rest.Host, svcCtx.Config.Rest.Port)
		group.Start()
		return nil
	})

	// add custom start logic
	eg.Go(func() error {
		svcCtx.Custom.Start()
		return nil
	})

	if err := eg.Wait(); err != nil {
		panic(err)
	}

	wailExit()
}

func printBanner(c config.Config) {
	figure.NewColorFigure(c.Banner.Text, c.Banner.FontName, c.Banner.Color, true).Print()
}

func init() {
	rootCmd.AddCommand(serverCmd)
}
