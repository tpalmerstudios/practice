#include <stdio.h>
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
 * ************/
int main (int argc, char* argv[])
{
}
