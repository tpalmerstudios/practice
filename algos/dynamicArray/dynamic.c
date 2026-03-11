#include "da.h"
#include <stdio.h>

int
main (void)
{
	ctDynamicArray_t da;

	/* initialize array for integers */
	if (ctDynamicArrayInit (&da, 4, sizeof (int)) != 0)
		{
			printf ("Init failed\n");
			return 1;
		}

	/* Push */
	for (int i = 1; i <= 5; i++)
		ctDynamicArrayPush (&da, &i);

	printf ("After push:\n");
	for (size_t i = 0; i < ctDynamicArraySize (&da); i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Insert */
	int x = 99;
	ctDynamicArrayInsert (&da, 2, &x);

	printf ("After insert at index 2:\n");
	for (size_t i = 0; i < ctDynamicArraySize (&da); i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Remove */
	int removed;
	ctDynamicArrayRemove (&da, 3, &removed);
	printf ("Removed value: %d\n", removed);

	printf ("After remove:\n");
	for (size_t i = 0; i < ctDynamicArraySize (&da); i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Pop */
	int popped;
	ctDynamicArrayPop (&da, &popped);
	printf ("Popped value: %d\n", popped);

	printf ("After pop:\n");
	for (size_t i = 0; i < ctDynamicArraySize (&da); i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Set */
	int newValue = 42;
	ctDynamicArraySet (&da, 1, &newValue);

	printf ("After set index 1:\n");
	for (size_t i = 0; i < ctDynamicArraySize (&da); i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Clear */
	ctDynamicArrayClear (&da);
	printf ("Size after clear: %zu\n", ctDynamicArraySize (&da));
	for (int i = 0; i < 10000; i++)
		{
			int v = i;
			ctDynamicArrayPush (&da, &v);

			if (i % 3 == 0) ctDynamicArrayInsert (&da, 0, &v);

			if (ctDynamicArraySize (&da) > 5 && i % 5 == 0) ctDynamicArrayRemove (&da, 2, &v);

			if (ctDynamicArraySize (&da) > 0 && i % 7 == 0) ctDynamicArrayPop (&da, &v);
		}
	printf ("Final size: %zu\n", ctDynamicArraySize (&da));
	for (size_t i = 0; i < ctDynamicArraySize (&da) && i < 10; i++)
		printf ("%d ", *(int *) ctDynamicArrayGet (&da, i));
	printf ("\n");

	/* Free */
	ctDynamicArrayFree (&da);

	return 0;
}
