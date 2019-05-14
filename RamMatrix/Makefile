CFLAGS=-c -I.
LFLAGS= -L. -L$(HOME)/Programming/Lib 
LIBS =-ldataStructures


RamMatrix: RamMatrix.o 
	g++ $(LFLAGS) -o RamMatrix RamMatrix.o 

RamMatrix.o: RamMatrix.cc 
	g++ $(CFLAGS) RamMatrix.cc


