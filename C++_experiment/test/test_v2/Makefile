# Set compile environment
#########################################
CCFLAGO	=-I../include -L../lib  -ltest
EXECNAME=v2-guolujie
INSTDIR	=./
LD_LIBRARY_PATH=../lib
#Run
#########################################
build:
	g++ -c ../src/p2.cpp ../src/v2.cpp 
	ar rcs ../lib/libtest.a   ./*.o
	g++  main.cpp  ${CCFLAGO} -o ${EXECNAME}
run:
	./${EXECNAME}
clean:
	rm ./*.o\
	&& rm ../lib/*\
	&& rm ${EXECNAME}
