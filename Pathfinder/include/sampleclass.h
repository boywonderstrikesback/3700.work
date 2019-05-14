#ifndef SAMPLERCLASS_H
#define SAMPLERCLASS_H
#include <stdlib.h> 
#include <vector>
#include "pathfinder.h"
class sampleclass{
	public:
		sampleclass(const int& Row, 
			const int& Columns, 
			uint8_t(*maze)[MAX_ROWS][MAX_COLS]);
			
			// tells if the current sample is zero
			int sampleiszero();
			
			//scans maze
			int scan(Cell cell2);
			
			//configures the maze
			Cell configure(int number);
			
			//tells status of maze
			bool Status(int item);
	private:
		uint8_t (*maze)[MAX_ROWS][MAX_COLS];
			int Row;
			int Columns;
			int quantity;
			int marks[10000];
};
#endif
