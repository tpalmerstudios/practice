#include <stdio.h>

int main (int argc, char *argv[])
{
	char* selection = NULL;
	size_t size = 0;
	ssize_t chars_read;
	int exit = 0;
	int menuChoice = 1;


	while (!exit)
	{
		chars_read = getline (&selection, &size, stdin);
		if (chars_read < 0)
		{
			printf ("Couldn't read input from user\n");
			free (selection);
			exit = 1;
			return -1;
		}
		// I totally over engineered this. I thought I was doing the program with the menu... I don't need all of that.
		menuChoice = validate (selection);
		switch (menuChoice)
		{
			case 1:
				break;
			case 2:
		}

	}
	free (selection);
	return 0;
}
