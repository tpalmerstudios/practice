#include "inventory.h"
#include <stdio.h>
#include <string.h>

void
displayMenu (void)
{
	printf ("Inventory Tracker\n");
	printf ("1.) Add Product\n");
	printf ("2.) List Products\n");
	printf ("3.) Update Quantity\n");
	printf ("4.) Total Value\n");
	printf ("0.) Exit\n");
}

void
addProduct (struct Product *array, int *count)
{
	if (*count >= 10)
		{
			printf ("We're all full!!!\n");
			return;
		}
	struct Product *p = array + *count;
	printf ("Enter the product name: ");
	scanf ("%31s", p->name);
	printf ("Enter the quantity of items: ");
	scanf ("%d", &p->quantity);
	printf ("Enter the price per item: $");
	scanf ("%f", &p->price);

	(*count)++;
	printf ("Product added.\n");
	printf ("Name: %s | Qty: %d | Price: $%.2f\n", p->name, p->quantity, p->price);
}

void
listProduct (const struct Product *array, int count)
{
	if (count <= 0 || array == NULL)
		{
			printf ("No products in inventory.\n");
			return;
		}
	const struct Product *p = array;
	printf ("All Products\n");
	for (int i = 0; i < count; i++, p++)
		{
			printf ("%d: %-20s | Qty: %3d | Price: $%.2f\n", i + 1, p->name, p->quantity, p->price);
		}
}

void
updateQuantity (struct Product *array, int count)
{
	if (count <= 0 || array == NULL)
		{
			printf ("No products in inventory.\n");
			return;
		}
	char input[32];
	printf ("Enter the name of the item to update: ");
	scanf ("%31s", input);
	for (struct Product *p = array; p < (array + count); p++)
		{
			if (strcmp (p->name, input) == 0)
				{
					printf ("Enter new quantity: ");
					scanf ("%d", &p->quantity);
					printf ("Quantity for %s has been updated to %d.\n", p->name, p->quantity);
					return;
				}
		}
	printf ("Product not found.\n");
	return;
}

void
inventoryValue (const struct Product *array, int count)
{
	if (count <= 0 || array == NULL)
		{
			printf ("No products in inventory.\n");
			return;
		}
	float total = 0;
	const struct Product *p = array;
	for (int i = 0; i < count; i++, p++)
		{
			total += p->quantity * p->price;
		}
	printf ("The total value of all inventory is: $%.2f\n", total);
}

void
saveProducts (const struct Product *array, int count)
{
	FILE *fp = fopen ("inventory.dat", "wb");
	if (!fp)
		{
			perror ("fopen");
			return;
		}
	fwrite (&count, sizeof (int), 1, fp);
	fwrite (array, sizeof (struct Product), count, fp);
	fclose (fp);

	printf ("Inventory saved %d items.\n", count);
	return;
}

int
loadProducts (struct Product *array, int maxCount)
{
	FILE *fp = fopen ("inventory.dat", "rb");
	if (!fp)
		{
			printf ("Nothing Saved\n");
			return 0;
		}
	int count = 0;
	if (fread (&count, sizeof (int), 1, fp) != 1)
		{
			printf ("Error opening file.\n");
			fclose (fp);
			return 0;
		}
	if (count > maxCount)
		{
			count = maxCount;
		}
	if (fread (array, sizeof (struct Product), count, fp) != (size_t) count)
		{
			printf ("Error reading data\n");
			fclose (fp);
			return 0;
		}
	fclose (fp);
	printf ("Loaded %d items from storage.\n", count);
	return count;
}
