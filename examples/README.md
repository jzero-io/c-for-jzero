# add

```shell
cd include
c-for-go generator.yaml
cd ..
gcc -fPIC -shared -o ./lib/add.so ./add.c
```