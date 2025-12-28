#include <stdio.h>

#define MIN -274
int f2c (int f);
int c2f (int c);

int main ()
{
	int c, temp;
	printf ("Temp Convertor\n");
	printf ("1) Fahrenheit to Celsius\n");
	printf ("2) Celsius to Fahrenheit\n");
	printf ("> ");
	c = getchar ();
	printf ("Temperature > ");

	switch (c)
	{
		case '1':
			printf ("Celsius temp is: %d\n", f2c (25));
			break;
		case '2':
			printf ("Fahrenheit temp is: %d\n", c2f (32));
			break;
		default:
			return 0;
	}
	return 0;
}

int f2c (int f)
{
	int c;
	c = 5 * ( f - 32) / 9;
	if (c < MIN)
		return 0;
	return c;
}

int c2f (int c)
{
	int f;
	f = ((c * 9) / 5) + 32;
	return f;
}
