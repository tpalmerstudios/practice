#ifndef INVENTORY_H
#define INVENTORY_H

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

void saveProducts (const struct Product *array, int count);
int loadProducts (struct Product *array, int maxCount);

#endif