
#include "sudoku.h"

// implementation of operations on sudoku
// refer to sudoku.h for description, usage, and exit status for functions
// comments here provide only implementation-related infomation

/*
void checkSquare(puzzle_t *puzzle, int row, int col, int *fillable);
void checkSquare(puzzle_t *puzzle, int row, int col, int *fillable){
	int fillableIndex;
	if( isFilled(puzzle, row, col) ){
		fillableIndex = getSquare(puzzle, row, col) - 1;
		fillable[fillableIndex] = 0;
	}
}

int 	fillSquare  	(puzzle_t *puzzle, int row, int col){
	// do some validation on puzzle
	if( !isValid(puzzle, row, col) ){
		return -1;
	}
	if( isFilled(puzzle, row, col) ){
		return 0;
	}

	int index, fillableIndex, rowIndex, colIndex, rowBegin, colBegin;
	int len = puzzle -> len;
	int slen= puzzle -> slen;
	int *fillable = (puzzle->map)[row][col].fillable;
	
	// check if row, column and grid suits are checked
	index = 0;
	rowBegin = slen * (row / slen);
	colBegin = slen * (col / slen);
	for( rowIndex = rowBegin; rowIndex < rowBegin + slen; rowIndex++){
		for( colIndex = colBegin; colIndex < colBegin + slen; colIndex++){
			checkSquare(puzzle, row, index, fillable);
			checkSquare(puzzle, index, col, fillable);
			checkSquare(puzzle, rowIndex, colIndex, fillable);
			index++;
		}
	}

	int choice=0, number;
	for(index = 0; index < len; index++){
		if( fillable[index] ){
			choice++;
			number = index + 1;
		}
	}
	switch( choice ){
		case 0: 	return 1; // infeasible solution to the puzzle
		case 1: 	setSquare(puzzle, row, col, number);
					return 0;
		default:	return 0; // does not fill
	}
}
*/

