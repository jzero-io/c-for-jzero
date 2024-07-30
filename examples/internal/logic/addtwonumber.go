package logic

import (
	"add/pkg/add"
	"context"

	"add/internal/svc"
	"add/internal/types"

	"github.com/zeromicro/go-zero/core/logx"
)

type AddTwoNumber struct {
	logx.Logger
	ctx    context.Context
	svcCtx *svc.ServiceContext
}

func NewAddTwoNumber(ctx context.Context, svcCtx *svc.ServiceContext) *AddTwoNumber {
	return &AddTwoNumber{
		Logger: logx.WithContext(ctx),
		ctx:    ctx,
		svcCtx: svcCtx,
	}
}

func (l *AddTwoNumber) AddTwoNumber(req *types.AddTwoNumberRequest) (resp *types.AddTwoNumberResponse, err error) {
	result := add.AddTwoNumber(int32(req.A), int32(req.B))
	resp = &types.AddTwoNumberResponse{}
	resp.Result = int(result)
	return
}
