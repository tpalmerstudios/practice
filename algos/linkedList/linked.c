#include "ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main (void)
{
	ctLL_t *ll = ctListInit (sizeof (int));
	srand ((unsigned) time (NULL));
	int i,j;
	int value, front, back;;
	if (ll == NULL)
		{
			printf ("Init failed\n");
			return 1;
		}
	for (i = 0; i < 30; i++)
		{
			value = rand () % 100;
			if (ctListInsertBack (ll, &value) != 0)
				{
					printf ("Insert failed\n");
					return 1;
				}
			else
				printf ("%2d - Inserted %d\n", i, value);
		}
	for (i = 0, j = 29; i < 15; i++,j--)
	{
		if (ctListPopFront (ll, &front) != 0)
			printf ("Pop Failed: %d", i);
		printf ("%2d - Retrieved %d\n", i, front);
		if (ctListPopBack (ll, &back) != 0)
			printf ("Pop Failed: %d", j);
		printf ("%2d - Retrieved %d\n", j, back);
	}

	ctListFree (ll);

	return 0;
}
