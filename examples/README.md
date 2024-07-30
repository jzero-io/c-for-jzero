# add

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