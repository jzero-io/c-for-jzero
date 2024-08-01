# c-for-jzero

c func convert to jzero server
* api
* proto

## config

```yaml
app: add
packages:
  - name: add
    paths:
      - ./pkg/add/add.go
jzero:
  branch: api
```

## example

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
