void detab (char s [], int tabwidth, int lim)
{
	int i; 
	int j = 0;
	char t [lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
	{
		t[i] = s[i];
	}
	t [i] = '\0';

	for (i = 0; t[i] != '\0' && i < lim; ++i)
	{
		if (t [i] == '\t')
		{
			do 
			{
				s [j] = ' ';
				++j;
			} while ((j % tabwidth) != 0);
			--j; // This was the bug. I was counting for both space + tabs
		}
		else
		{
			s[j] = t[i];
		}
		++j;
	}
	s [j+1] = '\0';
}

void fold (char s [], int linelength, int lim)
{
	int i, length, whiteloc;
	int pos = whiteloc = 0;
	char t [lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
	{
		t [i] = s [i];
	}
	t [i] = '\0';
	length = i;
	printf ("t string in fold: %s", t);
	for (i = 0; i < length; ++i)
	{
		if (t [i] == '\n')
		{
			pos = -1; // for the increment at the end
			s [i] = t [i];
			putchar (s [i]);
			whiteloc = 0;
		}
		else if (t [i] == ' ' || t [i] == '\t')
		{
			whiteloc = i;
			s [i] = t [i];
			putchar (s [i]);
		}
		//normal
		 else if (pos < linelength)
		{
			s [i] = t [i];
			putchar (s [i]);
		}
		else
		{
			if (whiteloc != 0)
			{
				s [whiteloc] = '\n';
				pos -= whiteloc;
				printf ("Found whiteloc at %d\n", whiteloc);
			}
			else
			{
				s [i - 3] = ' ';
				s [i - 2] = '-';
				s [i - 1] = ' ';
				s [i] = '\n';
				pos = 0;
				i -= 3;
				printf ("No whiteloc. Fold at %d\n", i);
			}
			// after using it reset
			whiteloc = 0;
		}
		++pos;
	}
	s [i] = '\0';
}

void entab (char s [], int tabwidth, int lim)
{
	int column = 0;
	int pos = 0;
	int consecutive = 0;
	int i;
	char t [lim];
	for (i = 0; i < lim && s [i] != '\0'; ++i)
{
		t [i] = s [i];
	}
	t [i] = '\0';
	for (i = 0; t[i] != '\0' && i < lim; ++i)
	{
		switch (t [i])
		{
			case ' ':
				++consecutive;
				++column;
				if (consecutive == tabwidth|| column % tabwidth == 0)
				{
					pos -= consecutive - 1;
					s [pos] = '\t';
					consecutive = 0;
				}
				else 
				{
					s [pos] = t [i];
				}
				break;
			case '\t':
				column += (tabwidth - (column % tabwidth));
				s [pos] = t [i];
				break;
			case '\n':
				column = 0;
				s [pos] = t [i];
				break;
			default:
				consecutive = 0;
				s [pos] = t [i];
				++column;
		}
		++pos;
	}
	s [pos+1] = '\0';
}

void reverse (char s [], int lim)
{
	char t [lim];
	int i, j;
	i = lim - 2;
	for (j = 0; j < lim; ++j)
	{
		t [j] = s [i];
		--i;
	}
	t [lim - 1] = '\0';
	for (i = 0; i < lim; ++i)
		s[i] = t [i];
}

