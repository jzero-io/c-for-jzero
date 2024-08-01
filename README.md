# c-for-jzero

c func convert to jzero server
* api
* proto

## 原理介绍

基于 c-for-go 工具生成出来的 go 代码, 使用 go ast 语法解析树对 go 代码进行解析, 获取函数的输入以及输出

进而生成 jzero 的可描述文件 api 文件或者 proto 文件

最后基于可描述文件, 自动生成服务端

## 配置项

* packages 为 c-for-go 工具生成的 go 代码的 package 名称以及生成的文件路径
* jzero 为 jzero 工具生成 rest 接口的相关配置

```yaml
packages:
  - name: add
    paths:
      - ./pkg/add/add.go
jzero:
  app: add
  branch: api
```

## 生成规范

* 如果函数的入参存在 golang 的引用类型, 那么即作为输入也作为输出

```go
func bulkUpdateAge(persons []Person) {
	for i := range persons {
		persons[i].Age++
	}
}
```

## examples

from:

```c
int AddTwoNumber(int a,int b);
```

to:

```api
syntax = "v1"

type AddTwoNumberRequest {
    a int32 `json:"a"`
    b int32 `json:"b"`
}

@server (
    prefix: /api/v1
    group:  add
)
service add {
    @handler AddTwoNumberHandler
    post /addTwoNumber (AddTwoNumberRequest) returns (int32)
}
```

and then:

```shell
jzero new add --branch api --output .
```
