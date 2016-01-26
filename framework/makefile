#############################################################

## 简洁通用的Makefile文件(Ver 1.1)
## Smart Makefile for general purpose (Ver 1.1)
## Author: 汤 永康 Yongkang TANG <tangyk%at%gmail>
## License: FreeBSD 
## Please use this makefile at YOUR OWN RISK !!!
## Source: https://github.com/tangyk/Smart-Makefile
## 功能： （1）自动搜索编译指定目录下的所有c/c++程序文件
##	  （2）自动搜索并包含（#include）指定目录下的头文件
##	   (3) 可一次性生成多个可执行文件
##	　 (4) 设置简单	
##
##  用法：  make   编译所有的应用程序
##          make [step4指定的某程序名]
##          make clean  清除obj文件
#############################################################
CC=g++

# Step1.设置第三方头文件的路径以及编辑参数.  比如 CFLAGS= -c -Wall -g -I/any/path/inlude
CFLAGS= -c -Wall -g 

# Step2.设置库文件以及库文件路径 比如 LIBS = -lGL -lGLU `pkg-config --libs opencv`
LIBS=  -lm

# Step3.制定程序的所在路径
# 路径不能以 [/] 符号结尾.  应设置为：  SRC_DIR = . , SRC_DIR = ./test1 
SRC_DIR = .

# Step4.需要生成的可执行程序列表 e.g. APP = app1 app2 app3
APP = app

#app_EXCL = ./test2/src/test3.cpp ./test2.cxx
# Step5.一个可执行程序只能有一个(main)入口。
# 当有多个应用程序时，需要设置生成各个可执行程序时，需要排除的程序文件列表
# 如果step4中指定的应用程序是server, 在生成server时，需要排除 ./client.c 以及 ./test1.c的话，应做如下设置
#server_EXCL = ./client.c ./test1.c 
# 以此类推。

########################### 请不要更改以下内容 ##########
EXTS := *.C *.c *.cxx *.CXX *.cpp *.CPP *.cc *.CC
DIRS := ${shell find ${SRC_DIR} -type d -print}
SRCS := $(foreach dir,$(DIRS),$(wildcard $(addprefix $(dir)/,$(EXTS))))
CFLAGS += $(foreach dir,$(DIRS), $(addprefix -I,$(dir)))
OBJS := $(addsuffix .o, $(SRCS))

define CMPL_APP
$(1): $(filter-out $(addsuffix .o,$(value $(1)_EXCL)), $(OBJS))
	$(CC) -o $(1) $(filter-out $(addsuffix .o, $(value $(addsuffix _EXCL, $(1)))), $(OBJS)) $(LIBS) $(value $(addsuffix _LIBS, $(1)))
endef

define CMPL_SRC
${1}.o:
	${CC} $(CFLAGS) ${1} -o ${1}.o
endef

.PHONY: all clean
.SUFFIXES:

all: $(APP)
	
$(foreach s,$(SRCS),$(eval $(call CMPL_SRC, $(s))))
$(foreach ap,$(APP),$(eval $(call CMPL_APP, $(ap))))

clean:
	rm -f ${OBJS} ${value APP}  
