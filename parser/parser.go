package parser

import (
	"fmt"
	"github.com/jzero-io/c-for-jzero/pkg/stringx"
	"go/ast"
	"go/parser"
	"go/token"
)

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
	Name string
	Type string
	Tag  string
}

func Parse(file string) ([]Route, error) {
	fset := token.NewFileSet()
	f, err := parser.ParseFile(fset, file, nil, parser.ParseComments)
	if err != nil {
		return nil, err
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
	return routes, nil
}
