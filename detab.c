#include <stdio.h>

#define MAXLINE 1000

void detab (char s [], int tabwidth, int lim);
int main ()
{
	int i, c, max;
	max = MAXLINE;
	char input [MAXLINE];
	for (i = 0; i < max && (c = getchar ()) != EOF; ++i)
	{
		input [i] = c;
	}
	detab (input, 8, max);
	printf ("\nDe-tabbed:\n%s\n", input);
	return 0;
}

// lim must be larger than true size to allow for conversion and extra chars
// TODO: add in a column tracker that accounts for newlines
// TODO: figure out why theres trailing dirty characters in s[]
void detab (char s [], int tabwidth, int lim)
{
	int i; 
	int j = 0;
	char t [lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
	{
		t[i] = s[i];
	}
	t [i] = '\0';

	for (i = 0; t[i] != '\0' && i < lim; ++i)
	{
		if (t [i] == '\t')
		{
			do 
			{
				s [j] = ' ';
				++j;
			} while ((j % tabwidth) != 0);
			--j; // This was the bug. I was counting for both space + tabs
		}
		else
		{
			s[j] = t[i];
		}
		++j;
	}
	s [j+1] = '\0';
}
