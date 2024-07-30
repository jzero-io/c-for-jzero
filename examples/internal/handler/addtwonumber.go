package handler

import (
	"net/http"

	"add/internal/logic"
	"add/internal/svc"
	"add/internal/types"
	"github.com/zeromicro/go-zero/rest/httpx"
)

func AddTwoNumber(svcCtx *svc.ServiceContext) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		var req types.AddTwoNumberRequest
		if err := httpx.Parse(r, &req); err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
			return
		}

		l := logic.NewAddTwoNumber(r.Context(), svcCtx)
		resp, err := l.AddTwoNumber(&req)
		if err != nil {
			httpx.ErrorCtx(r.Context(), w, err)
		} else {
			httpx.OkJsonCtx(r.Context(), w, resp)
		}
	}
}
