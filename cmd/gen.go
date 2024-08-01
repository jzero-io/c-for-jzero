package cmd

import (
	"os"
	"time"

	"github.com/jzero-io/c-for-jzero/config"
	"github.com/jzero-io/c-for-jzero/generator"
	"github.com/jzero-io/c-for-jzero/parser"
	"github.com/spf13/cobra"
	"gopkg.in/yaml.v3"
)

// genCmd represents the gen command
var genCmd = &cobra.Command{
	Use:   "gen",
	Short: "c-for-jzero gen",
	Long:  `c-for-jzero gen`,
	RunE:  gen,
}

func gen(_ *cobra.Command, _ []string) error {
	var conf config.Config

	file, err := os.ReadFile(CfgFile)
	if err != nil {
		return err
	}

	err = yaml.Unmarshal(file, &conf)
	if err != nil {
		return err
	}

	var groups []parser.Group

	for _, pkg := range conf.Packages {
		for _, path := range pkg.Paths {
			routes, err := parser.Parse(path)
			if err != nil {
				return err
			}
			groups = append(groups, parser.Group{
				Name:   pkg.Name,
				Routes: routes,
			})
		}
	}

	g := generator.New(groups)
	err = g.Gen(conf)
	if err != nil {
		return err
	}

	return nil
}

// initConfig reads in config file and ENV variables if set.
func initConfig() {
	if Debug {
		time.Sleep(time.Second * 15)
	}
}

func init() {
	rootCmd.AddCommand(genCmd)
}
