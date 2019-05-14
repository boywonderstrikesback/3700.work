CFLAGS=-c -I.
LFLAGS= -L. -L$(HOME)/Programming/Lib 
LIBS =-ldataStructures


lab4: lab4.o
	g++ $(LFLAGS) -o lab4 lab4.o

lab4.o: lab4.cc 
	g++ $(CFLAGS) lab4.cc

