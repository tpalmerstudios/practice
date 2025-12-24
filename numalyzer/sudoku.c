struct Cell
{
	int value;
	int candidates[9];
	int status;
}

enum Status {
	UNSOLVED = 0,
	SOLVED
};
int *loadedGame (char *gameFilePath);

Cell cell[9][9];
int *loaded = loadedGame ();
Status status;
for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			{
				cell[i][j].status = SOLVED;
				if ((cell[i][j].value = loaded[i * 9 + j]) == 0)
					{
						cell[i][j].status = UNSOLVED;
					}
				for (int k = 0; k < 9; i++)
					cell [i][j].candidates[k] = 1;
			}
	}
line checker
digit completer
for (int i = 0; i < 9 && !puzzleComplete(); i++)
{

	/**
	 * loop through the cells
	 * chack if unsolved and if cell == i
	 * if candidates only 1
	 * mark solved
	 * loop through vertical line
	 * loop through horizontal line
	 * loop through box
	 * /
}

fake solver


check solution

