#ifndef INVENTORY_H
#define INVENTORY_H

#define MAXCOUNT 1000
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
void loadProducts (struct Product *array, int maxCount);

#endif