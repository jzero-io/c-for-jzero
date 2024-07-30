package cmd

import (
	"fmt"
	"github.com/jzero-io/c-for-jzero/internal/tpl"
	"github.com/jzero-io/c-for-jzero/pkg/stringx"
	"github.com/jzero-io/c-for-jzero/pkg/templatex"
	"github.com/spf13/cobra"
	"go/ast"
	"go/parser"
	"go/token"
	"gopkg.in/yaml.v3"
	"os"
	"time"
)

type Config struct {
	App      string    `yaml:"app"`
	Packages []Package `yaml:"packages"`
}

type Package struct {
	Name  string   `yaml:"name"`
	Paths []string `yaml:"paths"`
}

// genCmd represents the gen command
var genCmd = &cobra.Command{
	Use:   "gen",
	Short: "c-for-jzero gen",
	Long:  `c-for-jzero gen`,
	RunE:  gen,
}

type Group struct {
	Name   string
	Routes []Route
}

type Route struct {
	Name     string
	Request  []Field
	Response []Field
}

type Field struct {
	Name string `yaml:"name"`
	Type string `yaml:"type"`
	Tag  string `yaml:"tag"`
}

func gen(_ *cobra.Command, _ []string) error {
	var config Config

	file, err := os.ReadFile(CfgFile)
	if err != nil {
		return err
	}

	err = yaml.Unmarshal(file, &config)
	if err != nil {
		return err
	}

	var groups []Group

	for _, pkg := range config.Packages {
		for _, path := range pkg.Paths {
			fset := token.NewFileSet()
			f, err := parser.ParseFile(fset, path, nil, parser.ParseComments)
			if err != nil {
				return err
			}
			var routes []Route

			ast.Inspect(f, func(n ast.Node) bool {
				// Check if the node is a function declaration
				if fn, ok := n.(*ast.FuncDecl); ok {
					// Function name
					funcName := fn.Name.Name

					// Function parameters
					var request []Field
					for _, param := range fn.Type.Params.List {
						for _, name := range param.Names {
							request = append(request, Field{
								Name: name.Name,
								Type: param.Type.(*ast.Ident).Name,
								Tag:  fmt.Sprintf("`json:\"%s\"`", stringx.FirstLower(name.Name)),
							})
						}
					}

					// Function return values
					var response []Field
					if fn.Type.Results != nil {
						for _, result := range fn.Type.Results.List {
							if len(result.Names) > 0 {
								for _, name := range result.Names {
									response = append(response, Field{
										Name: name.Name,
										Type: result.Type.(*ast.Ident).Name,
										Tag:  fmt.Sprintf("`json:\"%s\"`", stringx.FirstLower(name.Name)),
									})
								}
							} else {
								response = append(response, Field{
									Name: "resp",
									Type: result.Type.(*ast.Ident).Name,
									Tag:  fmt.Sprintf("`json:\"%s\"`", "resp"),
								})
							}
						}
					}
					routes = append(routes, Route{
						Name:     funcName,
						Request:  request,
						Response: response,
					})
				}
				return true
			})
			group := Group{
				Name:   pkg.Name,
				Routes: routes,
			}
			groups = append(groups, group)
		}
	}

	for _, group := range groups {
		template, err := templatex.ParseTemplate(map[string]interface{}{
			"Service": config.App,
			"Group":   group.Name,
			"Routes":  group.Routes,
		}, []byte(tpl.ApiTpl))
		if err != nil {
			return err
		}
		fmt.Println(string(template))
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
