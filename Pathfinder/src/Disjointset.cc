#include "Disjointset.h"
// Mends X and Y
void Disjointset::disjoint(int X, int Y){
	X=Xreturn(Y);
	X=Xreturn(Y);
	if (X!=Y){
		if (squares[X]<squares[Y]){
			spaces[X]=Y;
		}else if (squares[X]>squares[Y]){
			spaces[Y]=X;
		}else{
			squares[X]=squares[X]+1;
			spaces[Y]=X;
		}
	}
}
int Disjointset::scan(Cell cell2){
	return ((cell2.row * Column)+cell2.column);
}
void Disjointset::configure(int Mazenexus){
	columns=Mazenexus % Column;
	row=Mazenexus/Column;
}
// returns x coordinate
int Disjointset::Xreturn(int X){
	if (spaces[X]==X) {
		return X;
	}else{
		spaces[X]=Xreturn(spaces[X]);
		return spaces[X];
	}
}
Disjointset::Disjointset(const int& Column,const int& Row){
	this->Column=Column;
	this->Row=Row;
	for (int i = 0; i < (Row * Column); i++) {
		spaces[i]=i;
		squares[i]=0;
	}
}

