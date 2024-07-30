# c-for-jzero

c func convert to jzero server
* api
* proto

## example

from:

```c
int AddTwoNumber(int a,int b);
```

to:

```api
syntax = "v1"

type AddTwoNumberRequest {
  a int `json:"a"`
  b int `json:"b"`
}

type AddTwoNumberResponse {
  result int `json:"result"`
}

@server (
	prefix: /api/v1
)
service example {
	@handler AddTwoNumberHandler
	get /addTwoNumber (AddTwoNumberRequest) returns (AddTwoNumberResponse)
}
```

## new server by desc

```shell
jzero new demo --branch api --output .
```

