# add

## Install tools

```shell
# install c-for-go
go install github.com/xlab/c-for-go@latest

# install jzero
go install github.com/jzero-io/jzero@main
jzero check

# install c-for-jzero
go install github.com/jzero-io/c-for-jzero@main
```

## gen code

```shell
c-for-jzero gen
```

```shell
cd include
c-for-go -out ../pkg generator.yaml
cd ..
mkdir -p lib
gcc -fPIC -shared -o ./lib/libadd.so ./include/add.c

CGO_ENABLED=1 go build
jzero gen swagger
./add server
```