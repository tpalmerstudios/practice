#include <stdio.h>

int htoi (char s [])
{
	int i, n;
	n = 0;
	for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <='F') || (s[i==1] == 'x' || s[i==1] == 'X'); ++i)
	{
		switch (s[i])
		{
			case 'a':
			case 'A':
				n = 16 * n + 10;
				break;
			case 'b':
			case 'B':
				n = 16 * n + 11;
				break;
			case 'c':
			case 'C':
				n = 16 * n + 12;
				break;
			case 'd':
			case 'D':
				n = 16 * n + 13;
				break;
			case 'e':
			case 'E':
				n = 16 * n + 14;
				break;
			case 'f':
			case 'F':
				n = 16 * n + 15;
				break;
			case 'x':
			case 'X':
				break;
			default:
				n = 16 * n + (s[i] - '0');
		}
	}
	return n;
}

void strcat (char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0')
		;
}

void squeeze (char s[], char t[])
{
	int i, j;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; t[i] != '\0'; j++)
		{
			if (s[i] == t [j])
			{
				i++;
			}
		}
	}
}

int main ()
{
	printf ("0x58A in base 10 is %d\n", htoi ("00x58A"));
	return 0;
}
