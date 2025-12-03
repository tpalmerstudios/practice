#include <stdio.h>
#include "text.h"

#define MAXLINE 1000

void detab (char s [], int tabwidth, int lim);
void entab (char s [], int tabwidth, int lim);
void reverse (char s [], int lim);
void fold (char s [], int linelength, int lim);
int main ()
{
	int i, c, max;
	max = MAXLINE;
	char input [MAXLINE];
	for (i = 0; i < max && (c = getchar ()) != EOF; ++i)
	{
		input [i] = c;
	}
	fold (input, 10, max);
	printf ("\nFolded:\n%s\n", input);
	return 0;
}

// lim must be larger than true size to allow for conversion and extra chars
// TODO: add in a column tracker that accounts for newlines
// TODO: figure out why theres trailing dirty characters in s[]
