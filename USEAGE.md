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

# JNI封装

```
# 安装完swig, ant环境
apt-get install -y ant swig


cd /gdal-2.3.1
make install 
# 生成swig绑定和包装
cd swig/
rm -rf  /gdal-2.3.1/swig/java/apps/GDALtest.java
make ANDROID=yes
cd java
make ANDROID=yes
make clean
make

mkdir jni
cd jni/

cp /gdal-2.3.1/.libs/*gdal*.so    .
cp ../swig/java/**_wrap.cpp ./
cp ../swig/java/gdalconst_wrap.c ./
```