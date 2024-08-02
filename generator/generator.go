package generator

import (
	"github.com/jzero-io/c-for-jzero/config"
	"github.com/jzero-io/c-for-jzero/generator/tpl"
	"github.com/jzero-io/c-for-jzero/parser"
	"github.com/jzero-io/c-for-jzero/pkg/templatex"
	"os"
	"path/filepath"
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
	_ = os.MkdirAll(filepath.Join("desc", "api"), 0o755)
	for _, group := range g.Groups {
		template, err := templatex.ParseTemplate(map[string]interface{}{
			"Service": conf.Jzero.App,
			"Group":   group.Name,
			"Routes":  group.Routes,
		}, []byte(tpl.ApiTpl))
		if err != nil {
			return err
		}
		err = os.WriteFile(filepath.Join("desc", "api", group.Name+".api"), template, 0o644)
		if err != nil {
			return err
		}
	}
	return nil
}
