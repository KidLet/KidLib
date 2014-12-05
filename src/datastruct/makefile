#
# 文件名称：makefile
# 摘要：    编译整个项目的makefile，不包括测试模块
#

CC          	=  gcc
CXX         	=  g++
CFLAGS      	+= -g -fPIC -Wno-deprecated -Wall -Werror

SRC 			=  $(wildcard ./*.cpp)
OBJ 			=  $(patsubst %.cpp,%.o,$(SRC))
INCLUDE			=  -I./
LIB_64			=  -lpthread  
EXE				=  PushSoSo 

#------------------------------------------------------------------------------


#all: $(EXE)

-include ../make.rules
-include $(patsubst %.cpp,%.d,$(SRC))

#$(EXE): $(OBJ)
#	$(CXX) $(CFLAGS) $(OBJ) -o $(EXE) $(INCLUDE) $(LIB_64)

clean:
	@echo 'clean the project'
	@rm -f $(patsubst %.cpp,%.d,$(SRC))
	@rm -f $(patsubst %.cpp,%.o,$(SRC))
	@rm -f $(EXE)
.PHONY: clean

test:
	make -C ./test
.PHONY:	test

