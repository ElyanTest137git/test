
#ifndef SUDOKU_H
#define SUDOKU_H

// interface of operations on sudoku

/***
 * For words used for requirement level, as in must, must not, shall ...
 * please refer to http://tools.ietf.org/html/rfc2119
 *
 *** Returned value ***
 * If the returned value of a function indicates an exit status,
 * then 0 must be a normal exit
 * nagative integer must indicate an invalid argument
 * positive integer must indicate an runtime error
 * 
 * For a test function, as in isdigit(...) in <ctype.h>,
 * the returned value 1 shall indicate an yes,and 0 a no. // to-improve
 * The following prefixed is recommended: is-, has-, and use-.
 * You shall not use the word "not" in the function name.
 * Instead, choose an opposite word if necessary.
 *
 * If a pointer is to be returned, a null pointer indicates a failure.
 *** end ***
 *
 *** Naming conventions and Indentation***
 * CamelCase should be used to name both global variables and functions,
 * and recommended for most local ones.
 * Use 4-space tabs for indentation instead of space.
 * In vim, that is, set shiftwidth=4 tabstop=4 softabstop=0 noexpandtab
 *** end ***
 */


/***
 * my terminology for a n by n sudoku
 * length:	(a positive integer, denoted by n or len)
 * size:	size of a sudoku is n by n
 * square:	basic unit of a puzzle, in which you place a number within 1~n
 * suit:	n adjacent squares where you shall place a set of numbers from 1 to n. No repeated number is allowed.
 * row, column, grid:	suit of different types. A row and column is respectively n consecutive horizontal and verticle squares. A grid is a bigger square of total n squares, but sometimes an irregular shape.
 * note that a square belongs to one row, one column and at least one grid
 */

 /**
  * For now, the program doesn't interoperate with grid of irregular shape
  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	int 	number;
	int 	*fillable;
} square_t;


typedef	struct{
	int 		len;	// size of a sudoku is length by length
	square_t	**map;
	int 		slen;
	int 		isValid; // note the difference between valid and feasible
} puzzle_t;

square_t *newSquare 	(int len);
square_t *copySquare	(square_t *square);
void	deleteSquare	(square_t *square);
int 	isFilled    	(puzzle_t *puzzle, int row, int col);
int 	setSquare   	(puzzle_t *puzzle, int row, int col, int number);
int 	setSquareFillable(puzzle_t *puzzle, int row, int col, int number, int fillable);
int 	getSquare   	(puzzle_t *puzzle, int row, int col);
int 	getSquareFillable(puzzle_t *puzzle, int row, int col, int number);
void	updateFillable	(puzzle_t puzzle);

int 	fillSquare  	(puzzle_t *puzzle, int row, int col);
// should add another version of fillsquare(...)

puzzle_t *newPuzzle 	(int len);
puzzle_t *copyPuzzle	(puzzle_t *puzzle);
void 	deletePuzzle	(puzzle_t *puzzle);
int 	isValid     	(puzzle_t *puzzle, int row, int col);
int 	isComplete  	(puzzle_t *puzzle);
int 	isInfeasible	(puzzle_t *puzzle);


/**
 * The representation of a sudoku puzzle:
 * --------------------------------------
 * # comments
 * len
 * . . . . . ...
 * . . . . . ...
 * . . . . . ...
 * . . . . . ...
 * . . . . . ...
 * ......
 * -1
 * --------------------------------------
 * An integer (length) followed by len by len integers then -1.
 * len must be positive.
 * A sqaure is considered to be filled if the number is 1~n,
 * Otherwise it's considered empty. (0 is the recommended value)
 *
 * Lines starting by the symbol "#" is considered blank lines.
 * Blank lines are allowed.
 */
int 	fscanPuzzle  	(FILE *fd,	puzzle_t *puzzle);
int 	fprintPuzzle 	(FILE *fd,	puzzle_t *puzzle);
//void	setLayout   	()...



// private
//inline int at(int i, int j, int n);
#endif
