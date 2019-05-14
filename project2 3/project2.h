
#ifndef _PROJECT2_H
#define _PROJECT2_H


#include <iostream>
#include "simpleStack.h"


Stack<uint8_t> computer;

unsigned short board[9][9];


const unsigned short 
     VALID_MASK = 0b0011'1111'1110'0000,
     VALUE_MASK = 0b0000'0000'0000'1111,
     FILL_MASK = 0b0000'0000'0001'0000;



int validchoice(int,int);
int Count(unsigned short int);
bool findbest();
void Read();
void invalidchoice(int,int);
void Solve();
void print();
#endif	/* _welcome_H */