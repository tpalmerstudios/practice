#include "ll.h"
#include <stdio.h>

int
main (void)
{
	ctLL_t *ll = ctListInit (sizeof (int));
	if (ll == NULL)
		{
			printf ("Init failed\n");
			return 1;
		}
	int value = 1;
	int *data = &value;
	if (ctListInsertFront (ll, data) != 0)
	{
		printf ("Insert failed\n");
		return 1;
	}
	ctListFree (ll);

	return 0;
}
