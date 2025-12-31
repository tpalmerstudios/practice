#include <stdio.h>
#define LIMIT 100
int
main ()
{
	int i = 0;
	char s[LIMIT];
	char c;
	// Supposed to create a for loop without logical operators
	for (i = 0; i < LIMIT - 1; ++i)
		{
			if ((c = getchar ()) != '\n' && c != EOF) s[i] = c;
		}
}
