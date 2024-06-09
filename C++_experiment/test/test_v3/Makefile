# Set compile environment
#########################################
CCFLAGO	=-I../include -L../lib  -ltest
EXECNAME=v3-guolujie
INSTDIR	=./
#Run
#########################################
build:
	g++ -c ../src/p2.cpp ../src/p3.cpp ../src/v3.cpp
	ar rcs ../lib/libtest.a   ./*.o
	g++  main.cpp  ${CCFLAGO} -o ${EXECNAME}
run:
	./${EXECNAME}
clean:
	rm ./*.o\
	&& rm ../lib/*\
	&& rm ${EXECNAME}
