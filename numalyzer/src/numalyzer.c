#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *input (void);
int *sorter (int *unsorted);
void output (int *sorted);

enum charStates
{
	NUMBER,
	BLANK
};
int
main (int argc, char *argv[])
{
	printf ("Input a list of integers, separated by whitespace.\n");
	printf ("Press Ctrl-D when you're done.\n");

	output (sorter (input ()));
	return 0;
}

int *
input (int *listSize)
{
	int *inputlist = NULL;
	int maxLength = 256;
	int length = 0;
	int numberCount = 0;
	char currentLine[maxLength];
	while (fgets (currentLine, maxLength, stdin))
		{
			int cState = BLANK;
			length = strlen (currentLine);
			for (int i = 0; i < length; i++)
				{
					if (isdigit ((unsigned char) currentLine[i]))
						{
							if (cState == BLANK)
								{
									int *tmp = realloc (inputlist, ++numberCount * sizeof (int));
									if (!tmp)
										{
											free (inputlist);
											return NULL;
										}
									inputlist = tmp;
									inputlist[numberCount - 1] = currentLine[i] - '0';
								}
							else
								{
									inputlist[numberCount - 1]
										= inputlist[numberCount - 1] * 10 + (currentLine[i] - '0');
								}
							cState = NUMBER;
						}
					else
						{
							cState = BLANK;
						}
				}
		}
	*listSize = numberCount;
	return inputlist;
}
