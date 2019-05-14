#include "sampleclass.h"

sampleclass::sampleclass(const int& Row, 
const int& Columns,uint8_t(*maze)[MAX_ROWS][MAX_COLS]){

	///pointers for quanity of cells and maze
	this->quantity=Row * Columns * 4; 
	this->maze=maze;

	////pointer class for row and columns
	this->Row=Row;
	this->Columns=Columns;

///for loop to show quanity to be stored in marks array
	for (int b=0; b < quantity; b++) {
		marks[b]=b;
	}
}
////scans the given area(encode)
int sampleclass::scan(Cell cell2){
	return (cell2.row * Columns + cell2.column)*4 + cell2.direction;
}
///returns result (decode)
Cell sampleclass::configure(int number){
	Cell result;
	result.direction=number%4;
	result.column=(number/4)%Columns;
	result.row=number/(4*Columns);
	return result;
}
/////gives the overall status of the maze then returns through use of boolean
bool sampleclass::Status(int mark){
	Cell cell2=configure(mark);
	// First checking if wall exterior
	if (cell2.row==0){
		if (cell2.direction==0){return false;}
	}
	if (cell2.row==(Row - 1)){
		if (cell2.direction==2) {return false;}
	}
	if (cell2.column==0){
		if (cell2.direction==3) {return false;}
	}
	if (cell2.column==(Columns - 1)){
		if (cell2.direction == 1){return false;}
	}
switch (cell2.direction){
	case 0: 
		if (((*maze)[cell2.row][cell2.column] & WALL_UP)==0){return false;}
	case 1: 
		if (((*maze)[cell2.row][cell2.column] & WALL_RIGHT)==0){return false;}
	case 2: 
		if (((*maze)[cell2.row][cell2.column] & WALL_DOWN)==0){return false;}
	case 3: 
		if (((*maze)[cell2.row][cell2.column] & WALL_LEFT)==0){return false;}
	}
	return true;
}
///if sample is zero the result will be returned as zero
int sampleclass::sampleiszero(){
     int b=rand()%quantity;
	 int a=marks[b];
	 
	
	quantity--;
    marks[b]=marks[quantity - 1];
    return a;
}