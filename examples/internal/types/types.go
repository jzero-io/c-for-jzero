// Code generated by goctl-types plugin. DO NOT EDIT.
package types

import (
	"time"
)

var (
	_ = time.Now()
)

type AddTwoNumberRequest struct {
	A int `json:"a"`
	B int `json:"b"`
}

type AddTwoNumberResponse struct {
	Result int `json:"result"`
}
