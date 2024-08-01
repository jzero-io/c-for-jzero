package generator

import (
	"fmt"
	"github.com/jzero-io/c-for-jzero/config"
	"github.com/jzero-io/c-for-jzero/generator/tpl"
	"github.com/jzero-io/c-for-jzero/parser"
	"github.com/jzero-io/c-for-jzero/pkg/templatex"
)

type Generator struct {
	Groups []parser.Group
}

func New(groups []parser.Group) *Generator {
	return &Generator{
		Groups: groups,
	}
}

func (g *Generator) Gen(conf config.Config) error {
	for _, group := range g.Groups {
		template, err := templatex.ParseTemplate(map[string]interface{}{
			"Service": conf.App,
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
