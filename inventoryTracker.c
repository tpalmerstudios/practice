#include <stdio.h>
#include <string.h>

struct Product
{
	char name[32];
	int quantity;
	float price;
};

void displayMenu (void);
void addProduct (struct Product *array, int *count);
void listProduct (const struct Product *array, int count);
void updateQuantity (struct Product *array, int count);
void inventoryValue (const struct Product *array, int count);

int
main (int argc, char *argv[])
{
	struct Product products[10];
	int count = 0;
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
	return 0;
}

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
