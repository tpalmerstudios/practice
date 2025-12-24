#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 256

int
main (int argc, char *argv[])
{
	char line[256];
	int counts[52];
	for (int i = 0; i < 52;i++)
		counts [i] = 0;
	printf ("Put some fucking words on the screen\n");
	fgets (line, MAXLENGTH, stdin);
	for (i = 0; i < strlen (line); i++)
		{
			if (isalpha ((unsigned char) line[i]))

				{
					if (line[i] >= 'a' && line [i] <= 'z')
					{
						counts[line [i] - 'a']++;
					}
					else if (line[i] >= 'A' && line [i] <= 'Z')
					{
						counts[(line[i]- 'A') + 26]++;
					}
				}
		}
	int largest = counts [0] + counts [26];
	int mostPos = 0;
	for (i = 0; i < 26; i++)
	{
		printf ("%c is used %d times. %c is used %d times.\n", i + 'a', counts[i], i + 'A', counts [i + 26]);
		int total = counts [i] + counts [i + 26];
		if (total > largest)
		{
			larget = total;
			mostPos = i;
		}
	}
	printf ("The character used the most is \"%c\" used %d times.\n", mostPos + 'A', largest);
	return 0;

}

