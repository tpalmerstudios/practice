#include <stdio.h>
int
main ()
{
	int	 i	   = 0;
	int	 LIMIT = 100;
	char s[LIMIT];
	char c;
	// Supposed to create a for loop without logical operators
	for (i = 0; i < LIMIT - 1; ++i)
	{
		if ((c = getchar ()) != '\n')
		{
			if (c != EOF)
				s[i] = c;
		}
	}
}
