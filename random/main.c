#include <stdio.h>

int
main ()
{
	int c, i, j, k, nwhite, nother;
	int ndigit[10];
	int maxLoop = 0;

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar ()) != EOF)
		{
			if (c >= '0' && c <= '9')
				++ndigit[c - '0'];
			else if (c == ' ' || c == '\n' || c == '\t')
				++nwhite;
			else
				++nother;
		}
	printf ("\nDigits\n");
	printf (" 0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < 10; ++i)
		maxLoop = maxLoop > ndigit[i] ? maxLoop : ndigit[i];
	for (j = 0; j < maxLoop; ++j)
		{
			for (k = 0; k < 10; ++k)
				{
					if (j < ndigit[k])
						printf ("**");
					else
						printf ("  ");
				}
			putchar ('\n');
		}
	printf ("\nWhite space = %d, other = %d\n", nwhite, nother);
	return 0;
}
