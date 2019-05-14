#include <stack>
#include <iostream>
#include "Disjointset.h"
#include "pathfinder.h"
#include "sampleclass.h"


using namespace std;


///boolean to see if wall exist 
bool wallboolean(uint8_t(*maze)[MAX_ROWS][MAX_COLS],Cell cell2, 
	const int& Row, 
	const int& Columns);

//creates maze and then creates path
void makemaze(const int& Rows,const int& Column);
void makepath(uint8_t(*maze)[MAX_ROWS][MAX_COLS],
		const int Row, 
		const int Column);

///getting the total amount of space to check to see where all current/cells and 
//spaces are
///qCell=quantity of current cells
//// totalcell=grand total of all cells in given space
void gettotalspace(const Cell& qCell, Cell& totalCell);

// removing current square aka wall
void deletesquare(uint8_t(*maze)[MAX_ROWS][MAX_COLS], 
	const Cell& qCell, 
	const Cell& totalCell);

int main(){
	cout << "Enter starting coordinates:" << endl;
	int Row =-1;int Column =-1;
	do{
		cout << "Rows (Integer 0-51): ";
		cin >> Row;
		cout << "Columns (Integer 0-51): ";
		cin >> Column;
	}while (Row < 1||Row > 50 ||Column < 1||Column > 50);
        makemaze(Row, Column); 
		cout << "Maze generated \"maze.ps\"" << endl;
		return 0;
}
void makemaze(const int& Row, const int& Column){
	uint8_t maze[MAX_ROWS][MAX_COLS];
		int count = 0;
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Column; j++) {
			maze[i][j] = 15;
		}
	}
	Disjointset ds(Row,Column);
	sampleclass Sample(Row,Column, &maze);
	int i = 0, e = 0;
	Cell qCell, totalCell;
	while (i < (Row * Column) - 1){
		do{
			do {
				e = Sample.sampleiszero();
			}while(!Sample.Status(e));
			qCell = Sample.configure(e);
			gettotalspace(qCell, totalCell);
		}while(ds.Xreturn(ds.scan(qCell))==ds.Xreturn(ds.scan(totalCell)));
			ds.disjoint(ds.scan(qCell), ds.scan(totalCell));
			i++; deletesquare(&maze, qCell, totalCell);
	}
	
	printMaze(maze, Row, Column);
	makepath(&maze, Row, Column);
	
}
// makes current cell total to and stores to understand the total then confifures current 
//spot given the total amount of cells 
void gettotalCell(const Cell& qCell, Cell& totalCell){
	switch (qCell.direction) {
	
		case 0: 
			totalCell.row = qCell.row-1;
			totalCell.column = qCell.column;
		break;
	
		case 1: 
			totalCell.row=qCell.row;
			totalCell.column=qCell.column+1;
		break;
	
		case 2: 
			totalCell.row=qCell.row+1;
			totalCell.column=qCell.column;
		break;
	
		case 3: 
			totalCell.row=qCell.row;
			totalCell.column=qCell.column-1;
		break;
	}
	totalCell.direction = (qCell.direction + 2) % 4;
}
///wall boolean uses a case switch to see if wall exist. 
//this accueres by checking the given binary total (0-3) to see if a wall exist
bool wallboolean(uint8_t(*maze)[MAX_ROWS][MAX_COLS], Cell cell, 
	const int& Row, const int& Columns){

	switch (cell.direction){
		case 0: 
			if (((*maze)[cell.row][cell.column] & WALL_UP)==0) {return false;} 
		break;
		
		case 1: 
			if (((*maze)[cell.row][cell.column] & WALL_RIGHT)==0) { return false;} 
		break;
		
		case 2: 
			if (((*maze)[cell.row][cell.column] & WALL_DOWN)==0) {return false;} 
		break;
		
		case 3: 
			if (((*maze)[cell.row][cell.column] & WALL_LEFT)==0) {return false;} 
		break;
		}
		return true;
	}
// makes path by solving maze marks dead-ends/visted spaces
void makepath(uint8_t(*maze)[MAX_ROWS][MAX_COLS], 
	const int Row, const int Column){
	
	stack<Cell>input;	
		Cell total;
		Cell q{0,0,0};
			input.push(q);
			(*maze)[0][0]|=VISITED;

		while (true){
			q=input.top();
			if (q.row==(Row - 1)&&q.column==(Column - 1)){
			break;
		}
		if (q.direction==4){
			/// marks if location is dead end
			(*maze)[q.row][q.column] |= DEAD_END; 
			input.pop(); 
		}else{
			gettotalCell(q,total);
			Cell nextDirection = q; 
			nextDirection.direction = nextDirection.direction + 1;
			input.pop();
			input.push(nextDirection);
				// if statement tells if maze has been visted
				if (!wallboolean(maze, q, Row, Column)&& 
					((*maze)[total.row][total.column] & VISITED)==0){
					total.direction = 0;
					input.push(total);
					(*maze)[total.row][total.column]|=VISITED; 
			}
		}
	}
}
///removes any in the way square from randomized path
void deletessquare(uint8_t(*maze)[MAX_ROWS][MAX_COLS],const Cell& qCell, 
	const Cell& totalCell) {

switch (qCell.direction){
	case 0: 
		(*maze)[qCell.row][qCell.column]^=WALL_UP; 
		break;
	case 1: 
		(*maze)[qCell.row][qCell.column]^=WALL_RIGHT; 
		break;
	case 2: 
		(*maze)[qCell.row][qCell.column]^=WALL_DOWN; 
		break;
	case 3: 
		(*maze)[qCell.row][qCell.column]^=WALL_LEFT; 
		break;
	}
	////gets the total of all spaces and if a wall exist for the given pathway
	///// the break statement wil remove given square(wall)
switch (totalCell.direction){
	case 0: 
		(*maze)[totalCell.row][totalCell.column]^=WALL_UP; 
		break;
	case 1: 
		(*maze)[totalCell.row][totalCell.column]^= WALL_RIGHT; 
		break;
	case 2: 
		(*maze)[totalCell.row][totalCell.column]^=WALL_DOWN; 
		break;
	case 3: 
		(*maze)[totalCell.row][totalCell.column]^=WALL_LEFT; 
		break;
	}
}