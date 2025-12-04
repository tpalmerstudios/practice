void detab (char s[], int tabwidth, int lim)
{
	int i;
	int j = 0;
	char t[lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		{
			t[i] = s[i];
		}
	t[i] = '\0';

	for (i = 0; t[i] != '\0' && i < lim; ++i)
		{
			if (t[i] == '\t')
				{
					do
						{
							s[j] = ' ';
							++j;
						}
					while ((j % tabwidth) != 0);
					--j; // This was the bug. I was counting for both space +
						 // tabs
				}
			else
				{
					s[j] = t[i];
				}
			++j;
		}
	s[j + 1] = '\0';
}

void fold (char s[], int linelength, int lim)
{
	int i, j, length, whiteloc, whitepos;
	int pos = j = whiteloc = whitepos = 0;
	char t[lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		{
			t[i] = s[i];
		}
	t[i] = '\0';
	length = i;
	for (i = 0; i < length; ++i)
		{
			if (t[i] == '\n')
				{
					pos = -1; // for the increment at the end
					s[j] = t[i];
					whiteloc = whitepos = 0;
				}
			else if (t[i] == ' ' || t[i] == '\t')
				{
					whiteloc = j;
					whitepos = pos;
					s[j] = t[i];
				}
			// normal
			else if (pos < linelength)
				{
					s[j] = t[i];
				}
			else
				{
					if (whiteloc != 0)
						{
							s[whiteloc] = '\n';
							pos = (pos - whitepos) - 1;
						}
					else
						{
							s[j - 2] = ' ';
							s[j - 1] = '-';
							s[j] = '\n';
							pos = -1;
							i -= 4;
						}
					whiteloc = whitepos = 0;
				}
			++j;
			++pos;
		}
	s[i] = '\0';
}

void entab (char s[], int tabwidth, int lim)
{
	int column = 0;
	int pos = 0;
	int consecutive = 0;
	int i;
	char t[lim];
	for (i = 0; i < lim - 1 && s[i] != '\0'; ++i)
		{
			t[i] = s[i];
		}
	t[i] = '\0';
	for (i = 0; t[i] != '\0' && i < lim; ++i)
		{
			switch (t[i])
				{
				case ' ':
					++consecutive;
					++column;
					if (consecutive == tabwidth || column % tabwidth == 0)
						{
							pos -= consecutive - 1;
							s[pos] = '\t';
							consecutive = 0;
						}
					else
						{
							s[pos] = t[i];
						}
					break;
				case '\t':
					column += (tabwidth - (column % tabwidth));
					s[pos] = t[i];
					break;
				case '\n':
					column = 0;
					s[pos] = t[i];
					break;
				default:
					consecutive = 0;
					s[pos] = t[i];
					++column;
				}
			++pos;
		}
	s[pos] = '\0';
}

void reverse (char s[], int lim)
{
	char t[lim];
	int i, j;
	i = lim - 2;
	for (j = 0; j < lim; ++j)
		{
			t[j] = s[i];
			--i;
		}
	t[lim - 1] = '\0';
	for (i = 0; i < lim; ++i)
		s[i] = t[i];
}

// returns location of next char
int nextChar (char s[], int i, char c, int lim)
{
	while (s[i] != '\0' && i < lim)
		{
			if (s[i] == c)
				return i;
			++i;
		}

	return 0;
}

int isPrepend (char s[], int i, char c, int lim)
{
	if (i > lim - 1 || i < 0)
		return -1;
	if (s[i - 1] == c)
		return 1;
	return 0;
}
int isPostpend (char s[], int i, char c, int lim)
{
	if (i > lim - 2 || i < 0)
		return -1;
	if (s[i + 1] == c)
		return 1;
	return 0;
}

void skipComments (char s[], int lim)
{
	// copy loop to t
	// Loop to find next ", ', / not prepended with \ and /* and // and \n and */
	// switch case if none of the others are flag
	// set flag of in quote single or comment
	// quote -> s ++j
	// single -> s ++j
	// singleline \n stops flag save loc of start. no ++j
	// block */ stops flag no ++j
}
