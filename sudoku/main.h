#ifndef BOARD_H
#define BOARD_H

#define MAXCHARS 82

typedef enum solveState
{
	SOLVED = 0,
	UNSOLVED
} solveState;

typedef struct Cell
{
	char value;
	// Candidates will be 1 for potential, 0 for not 
	int candidates[9];
	solveState solved;
} Cell;
typedef struct Board
{
	Cell cell[81];
} Board;

char *loadPuzzle (char *puzzlePath);
int savePuzzle (const Board *board);

void puzzleGrid (const Board *board);
void menuSelect (void);

const char *menuChoice (void);
const char *numberInput (void);

int checker (const Board *board);

int validator (const char *inputString);

Board* solver (const Board *board);
int deducer (Board *board, char testValue);
int bruteforce (Board *board);

// Board Module?
#endif // BOARD_H

