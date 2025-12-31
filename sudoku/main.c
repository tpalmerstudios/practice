#include "main.h"

#define MAXCHARS 82
/*****
 * peristence
 * output
 * input
 * checker
 * validator
 * solver
 * bruteforce
 * deduction
 * board
 */
/****************
 * SOLVER
 * int consecutiveLoops = 0;
 * int changes = 0;
 * Board tempBoard = memcpy (board);
 * solveState solved = UNSOLVED;
 * do
 * {
 *	do
 *	{
 *		for (char i = '1'; i <= '9'; i++)
 *		{
 *			if (deducitve (tempBoard, i) != 0)
 *			{
 *				changes = 1;
 *				consecutiveLoops = 0;
 *			}
 *		}
 *		if (changes == 0)
 *			consecutiveLoops++;
 *		changes = 0;
 *
 *	} while (consecutiveLoops < 2)
 *	if (bruteforce (tempBoard) != 0)
 *		// ERRORS
 *	else
 *	{
 *		if (checker (tempBoard) == 1)
 *			return tempBoard;
 *	}
 * } while (solved == UNSOLVED)
 *
 * ************/

findUnfilled
for (i = 0; i < 81; i++)
{
	if (cell [i / 9] [i % 9].solveState == UNSOLVED)
		return i;
	retun 0;
}
stateManager
	validateBoard(board);
	while (findUnfilled)
	load candidate arrays and set solve states
	iterate 1-9 to deduce
	run until we have a full loop with no changes or until solved
	once no change state is in test mode
	call backtrace
		call findUnfilled
		set to lowest candidate
		deduce 2 times or until failure
		if failure we remove this item from candidate
		then call backtrace
	check

deduce

dHLine
dVLine
dFamily

deduce
board state = good

state mangager determines recursion
bruteforce
while findUnfilled
lowest candidate
board state = test
deduce
check


int main (int argc, char* argv[])
{
}
