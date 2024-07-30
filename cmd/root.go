package cmd

import (
	"github.com/spf13/cobra"
	"os"
)

var (
	CfgFile string
	Debug   bool
)

// rootCmd represents the base command when called without any subcommands
var rootCmd = &cobra.Command{
	Use:   "c-for-jzero",
	Short: "c-for-jzero root",
	Long:  "c-for-jzero root.",
}

// Execute adds all child commands to the root command and sets flags appropriately.
// This is called by main.main(). It only needs to happen once to the rootCmd.
func Execute() {
	err := rootCmd.Execute()
	if err != nil {
		os.Exit(1)
	}
}

func init() {
	cobra.OnInitialize(initConfig)

	rootCmd.PersistentFlags().StringVar(&CfgFile, "config", "c-for-jzero.yaml", "set c-for-go config file")
	rootCmd.PersistentFlags().BoolVarP(&Debug, "debug", "d", false, "enable debug mode")
}
