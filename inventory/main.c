#include "inventory.h"
#include <stdio.h>

int
main (int argc, char *argv[])
{
	struct Product products[10];
	int count = loadProducts (products, 10);
	int quit = 0;
	char input;
	while (!quit)
		{
			displayMenu ();

			input = getchar ();
			while ((getchar ()) != '\n')
				;

			switch (input)
				{
				case '1':
					addProduct (products, &count);
					break;
				case '2':
					listProduct (products, count);
					break;
				case '3':
					updateQuantity (products, count);
					break;
				case '4':
					inventoryValue (products, count);
					break;
				case '0':
					quit = 1;
					break;
				default:
					printf ("Invalid input, try again.\n");
					break;
				}
		}
	// saveProducts (products, count);
	printf ("Inventory Saved. Exiting.\n");
	return 0;
}
