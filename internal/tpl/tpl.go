package tpl

var ApiTpl = `syntax = "v1"

{{range $v := .Routes | uniq}}type {{$v.Name | FirstUpper}}Request {
{{range $field := $v.Request}}
	{{$field.Name}} {{$field.Type}} {{$field.Tag}}
	{{end}}
}
{{if gt (len .Response) 1}}
type {{$v.Name | FirstUpper}}Response {
    {{range $field := $v.Response}}{{$field.Name}} {{$field.Type}} {{$field.Tag}}
{{end}}
}{{else}}{{end}}
{{end}}
@server (
    prefix: /api/v1
    group:  {{ .Group }}
)
service {{ .Service }} {
    {{range $v := .Routes | uniq}}@handler {{$v.Name}}Handler
    post /{{$v.Name | FirstLower}} ({{$v.Name | FirstUpper}}Request) returns ({{if gt (len $v.Response) 1}}{{$v.Name | FirstUpper}}Response{{else if eq (len $v.Response) 1}}{{(index $v.Response 0).Type}}{{end}})
    {{end}}
}
`
