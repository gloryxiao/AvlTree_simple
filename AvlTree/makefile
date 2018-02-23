# this is a makefile to test avltree
#
# Author : Sean
# Date: Jan 3, 2018

CC = g++
FLAG = -g -c -I${DIR_INC}
DIR_SRC = ./src
DIR_INC = ./include
DIR_OBJ = ./obj
DIR_BIN = ./bin

ll=ls -al
SRC = $(wildcard ${DIR_SRC}/*.cpp)
OBJ = $(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC}))
  
  

TARGET = test
BIN_TARGET = ${DIR_BIN}/${TARGET}

$(BIN_TARGET): ${OBJ}
	$(CC) -o $@ $(OBJ)

${DIR_OBJ}/%.o: ${DIR_SRC}/%.cpp
	$(CC) $(FLAG) $<  -o $@

clean:
	cd $(DIR_OBJ) && pwd && ls -al
	cd $(DIR_OBJ) ; pwd; $(ll)
	cd $(DIR_OBJ) 
	pwd
	ls -al
	#cd $(DIR_OBJ) && rm -f *.o
.PHONY: clean

	

