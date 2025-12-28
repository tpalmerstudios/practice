// Recommended unsigned char cast.
// isalnum((unsigned char) c);
int isalnum (int c)
{
	if (isalpha (c) || isdigit (c))
		return 1;
	return 0;
}

int isalpha (int c)
{
	if (islower (c)|| isupper (c))
		return 1;
	return 0;
}

int islower (int c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	return 0;
}

int isupper (int c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int isdigit (int c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int isxdigit (int c)
{
	if (isdigit (c) || ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
		return 1;
	return 0;
}

// TODO: Verify iscntrl checks for all control characters
int iscntrl ()
{
	if (c == 0x00 || c == 0x1F || c == 0x7F)
		return 1;
	return 0;
}
//TODO add iscntrl() and isgraph()
//TODO: Create an atof - floating point
 
int atoi (char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s [i] <= '9'; ++i)
		n = 10 * n + (s [i] - '0');			// This takes the current value and multiplies it by 10 before adding the current char
	return n;
}

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

int tolower (int c)
{
	if (isupper (c))
		return c + 'a' - 'A';
	else
		return c;
}

// Random number generator - not for production code
int rand (unsigned int next)
{
	next = next * 1103515245 + 12345;
	return (unsigned int) (next/65536) % 32768;
}

void squeeze (char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++]  s[i];
	s[j] = '\0';
}
