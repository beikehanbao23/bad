# 使用

`Makefile` 中指令是各个镜像编译指令大全

# 编译Docker镜像方法

使用默认版本

`make gdal`

指定版本

`make sqlite3/3.21.0`

传递参数

`make BUILD_ARGS="--no-cache" sqlite3`

# 常见问题

## 1.docker版本问题

报错 
```
    Please provide a source image with `from` prior to commit
```

解决方法

https://www.codenong.com/cs105407586/