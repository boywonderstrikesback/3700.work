CFLAGS=-c -I.
LFLAGS= -L. -L$(HOME)/Programming/Lib 
LIBS =-ldataStructures


project2: project2.o 
	g++ $(LFLAGS) -o project2 project2.o 

project2.o: project2.cc 
	g++ $(CFLAGS) project2.cc
