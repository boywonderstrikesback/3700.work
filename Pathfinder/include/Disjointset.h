#ifndef DISJOINT_H
#define DISJOINT_H
#include "pathfinder.h"

class Disjointset{
	private:
		int spaces[2500];
		int squares[2500];
			int row;
			int Row;
			int columns;
			int Column;
	public:
		Disjointset(const int& Row,const int& Column);
			void disjoint(int X,int Y);
			//for X coordinate
				int Xreturn(int X);
			//scans variable then re-configures it 
				int scan(Cell cell2);
				void configure(int Mazenexus);
};
#endif