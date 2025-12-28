/**
 * @file text.h
 * @brief Text utility routines for formatting and validation.
 *
 * Proposed improvements:
 * - Separate declarations and definitions to reduce header coupling and improve
 * build hygiene.
 * - Add explicit bounds checking for all array accesses to prevent undefined
 * behavior on malformed input.
 * - Replace variable-length arrays with dynamic allocations or fixed maximum
 * sizes to clarify ownership and lifetime.
 * - Return error codes instead of printing directly in helpers so callers can
 * respond appropriately.
 * - Normalize tab/space handling and expose configuration through function
 * parameters where sensible.
 * - Add unit tests covering nested comments, escaped delimiters, and empty
 * input to ensure edge cases are handled.
 */

/**
 * @brief Reverse a string in place.
 *
 * @param s   Target string to reverse.
 * @param lim Maximum length of the buffer, including the null terminator.
 */
void
reverse (char s[], int lim)
{
	char t[lim];
	int	 i, j;
	i = lim - 2;
	for (j = 0; j < lim; ++j)
		t[j] = s[i--];
	t[lim - 1] = '\0';
	for (i = 0; i < lim; ++i)
	{
		s[i] = t[i];
	}
}

/**
 * @brief Find the next occurrence of a character within a string.
 *
 * @param s   Input string to scan.
 * @param i   Starting index for the search.
 * @param c   Character to look for.
 * @param lim Maximum length of the string buffer.
 * @return Index of the next matching character or 0 if not found before the
 * limit.
 */
int
nextChar (char s[], int i, char c, int lim)
{
	while (s[i] != '\0' && i < lim)
	{
		if (s[i] == c)
		{
			return i;
		}
		++i;
	}

	return 0;
}

/**
 * @brief Check if a character appears immediately before an index.
 *
 * @param s   String to inspect.
 * @param i   Index to check relative to.
 * @param c   Character to test for.
 * @param lim Maximum valid length of the buffer.
 * @return 1 when the preceding character matches, 0 when it does not, and -1 on
 * out-of-range input.
 */
int
isPrepend (char s[], int i, char c, int lim)
{
	if (i > lim - 1 || i < 0)
	{
		return -1;
	}
	if (s[i - 1] == c)
	{
		return 1;
	}
	return 0;
}

/**
 * @brief Check if a character appears immediately after an index.
 *
 * @param s   String to inspect.
 * @param i   Index to check relative to.
 * @param c   Character to test for.
 * @param lim Maximum valid length of the buffer.
 * @return 1 when the following character matches, 0 when it does not, and -1 on
 * out-of-range input.
 */
int
isPostpend (char s[], int i, char c, int lim)
{
	if (i > lim - 2 || i < 0)
	{
		return -1;
	}
	if (s[i + 1] == c)
	{
		return 1;
	}
	return 0;
}

/**
 * @brief Replace tabs with spaces according to a tab width.
 *
 * @param s        String to modify.
 * @param tabwidth Number of spaces representing a tab stop.
 * @param lim      Maximum length of the buffer.
 */
void
detab (char s[], int tabwidth, int lim)
{
	int	 i;
	int	 j = 0;
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
				s[j++] = ' ';
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

/**
 * @brief Strip C-style line and block comments while tracking delimiters.
 *
 * Maintains simple state to avoid removing comment markers found inside string
 * or character literals and performs lightweight delimiter balance checks.
 *
 * @param s   Buffer containing the source text to clean.
 * @param lim Maximum length of the buffer.
 */
void
skipComments (char s[], int lim)
{
	char c, t[lim];
	int	 i, j, k, isSpecial;
	// Flags that tell if I'm currently in one
	struct Flags
	{
		int	 dQuote;
		int	 sQuote;
		int	 sComment;
		int	 bComment;
		int	 nl;
		char parStack[100];
	};
	// Probably make the sruct global as well as the initialization
	struct Flags f = {0, 0, 0, 0, 0, ""};
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		t[i] = s[i];
	t[i] = '\0';

	j = k = 0;
	// Loop through each char of the string
	for (i = 0; t[i] != '\0'; ++i)
	{
		// Current char
		c = t[i];
		isSpecial = (c == '"' || c == '\'' || c == '/' || c == '[' || c == ']' || c == '{'
					 || c == '}' || c == '(' || c == ')');
		if (c == '\n' || (isSpecial && isPrepend (t, i, '\\', lim) != 1))
		{
			switch (c)
			{
			case '"':
				if (f.dQuote)
					f.dQuote = 0;
				else if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.dQuote = 1;
				break;
			case '\'':
				if (f.sQuote)
					f.sQuote = 0;
				else if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.sQuote = 1;
				break;
			case '/':
				if (f.bComment && isPrepend (t, i, '*', lim) == 1)
				{
					f.bComment = 0;
					// This could probably be done cleaner, but
					// when I set blockcomment to 0 the final
					// '/' is added to the string
					++i;
				}
				else if (isPostpend (t, i, '/', lim) == 1 && !f.dQuote && !f.sQuote && !f.bComment
						 && !f.sComment)
					f.sComment = 1;
				if (isPostpend (t, i, '*', lim) == 1 && !f.dQuote && !f.sQuote && !f.bComment
					&& !f.sComment)
					f.bComment = 1;
				break;
			case '\n':
				f.sComment = 0;
				++f.nl;
				break;
				// I should make this a new function with the global
				// flags
			case '(':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case ')':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '(')
						printf (
							"Error: Unclosed Parenthesis "
							"at Line %d\n",
							f.nl + 1);
				break;
			case '[':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case ']':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '[')
						printf (
							"Error: Unclosed Bracket "
							"at Line %d\n",
							f.nl + 1);
				break;
			case '{':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case '}':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '{')
						printf (
							"Error: Unclosed Brace "
							"at Line %d\n",
							f.nl + 1);
				break;
			}
		}
		if (!f.bComment && !f.sComment)
			s[j++] = t[i];
	}
	s[j] = '\0';
	if (k != 0)
	{
		printf ("Unclosed Parenthesis, Brackets, or Braces\n");
	}
	j = k = 0;
	// Loop through each char of the string
	for (i = 0; t[i] != '\0'; ++i)
	{
		// Current char
		c = t[i];
		isSpecial = (c == '"' || c == '\'' || c == '/' || c == '[' || c == ']' || c == '{'
					 || c == '}' || c == '(' || c == ')');
		if (c == '\n' || (isSpecial && isPrepend (t, i, '\\', lim) != 1))
		{
			switch (c)
			{
			case '"':
				if (f.dQuote)
					f.dQuote = 0;
				else if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.dQuote = 1;
				break;
			case '\'':
				if (f.sQuote)
					f.sQuote = 0;
				else if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.sQuote = 1;
				break;
			case '/':
				if (f.bComment && isPrepend (t, i, '*', lim) == 1)
				{
					f.bComment = 0;
					// This could probably be done cleaner, but
					// when I set blockcomment to 0 the final
					// '/' is added to the string
					++i;
				}
				else if (isPostpend (t, i, '/', lim) == 1 && !f.dQuote && !f.sQuote && !f.bComment
						 && !f.sComment)
					f.sComment = 1;
				if (isPostpend (t, i, '*', lim) == 1 && !f.dQuote && !f.sQuote && !f.bComment
					&& !f.sComment)
					f.bComment = 1;
				break;
			case '\n':
				f.sComment = 0;
				++f.nl;
				break;
				// I should make this a new function with the global
				// flags
			case '(':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case ')':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '(')
						printf (
							"Error: Unclosed Parenthesis "
							"at Line %d\n",
							f.nl + 1);
				break;
			case '[':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case ']':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '[')
						printf (
							"Error: Unclosed Bracket at "
							"Line %d\n",
							f.nl + 1);
				break;
			case '{':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					f.parStack[k++] = c;
				break;
			case '}':
				if (!f.sQuote && !f.dQuote && !f.sComment && !f.bComment)
					if (k > 0 && f.parStack[--k] != '{')
						printf (
							"Error: Unclosed Brace at Line "
							"%d\n",
							f.nl + 1);
				break;
			}
		}
		if (!f.bComment && !f.sComment)
			s[j++] = t[i];
	}
	s[j] = '\0';
	if (k != 0)
		printf ("Unclosed Parenthesis, Brackets, or Braces\n");
}

/**
 * @brief Fold long lines by inserting line breaks at whitespace.
 *
 * Splits lines at the nearest prior whitespace when exceeding the desired
 * width and uses hyphenation when no whitespace is available nearby.
 *
 * @param s          String to wrap.
 * @param linelength Desired maximum line length.
 * @param lim        Maximum buffer length.
 */
void
fold (char s[], int linelength, int lim)
{
	int	 i, j, length, whiteloc, whitepos;
	int	 pos = j = whiteloc = whitepos = 0;
	char t[lim];
	for (i = 0; i < lim && s[i] != '\0'; ++i)
		t[i] = s[i];
	t[i]   = '\0';
	length = i;
	for (i = 0; i < length; ++i)
	{
		if (t[i] == '\n')
		{
			pos		 = -1; // for the increment at the end
			s[j]	 = t[i];
			whiteloc = whitepos = 0;
		}
		else if (t[i] == ' ' || t[i] == '\t')
		{
			whiteloc = j;
			whitepos = pos;
			s[j]	 = t[i];
		}
		// normal
		else if (pos < linelength)
			s[j] = t[i];
		else
		{
			if (whiteloc != 0)
			{
				s[whiteloc] = '\n';
				pos			= (pos - whitepos) - 1;
			}
			else
			{
				s[j - 2] = ' ';
				s[j - 1] = '-';
				s[j]	 = '\n';
				pos		 = -1;
				i -= 4;
			}
			whiteloc = whitepos = 0;
		}
		++j;
		++pos;
	}
	s[i] = '\0';
}

/**
 * @brief Compress runs of spaces into tabs where appropriate.
 *
 * @param s        String to modify.
 * @param tabwidth Tab stop width used to align output.
 * @param lim      Maximum buffer length.
 */
void
entab (char s[], int tabwidth, int lim)
{
	int	 column		 = 0;
	int	 pos		 = 0;
	int	 consecutive = 0;
	int	 i;
	char t[lim];
	for (i = 0; i < lim - 1 && s[i] != '\0'; ++i)
		t[i] = s[i];
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
				s[pos]		= '\t';
				consecutive = 0;
			}
			else
				s[pos] = t[i];
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
			s[pos]		= t[i];
			++column;
		}
		++pos;
	}
	s[pos] = '\0';
}

