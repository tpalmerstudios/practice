/**
 * @file text.c
 * @brief Driver showcasing text utility routines for formatting and comment
 * stripping.
 */

#include "text.h"
#include <stdio.h>

#define MAXLINE 1000

/** @brief Replace tabs with spaces in the supplied buffer. */
void detab (char s[], int tabwidth, int lim);
/** @brief Convert appropriate runs of spaces back to tabs. */
void entab (char s[], int tabwidth, int lim);
/** @brief Reverse the given buffer in place. */
void reverse (char s[], int lim);
/** @brief Fold long lines using the configured line length. */
void fold (char s[], int linelength, int lim);
/** @brief Remove C-style comments while respecting quoted literals. */
void skipComments (char s[], int lim);
/** @brief Check for a trailing character relative to an index. */
int isPostpend (char s[], int i, char c, int lim);
/** @brief Check for a preceding character relative to an index. */
int isPrepend (char s[], int i, char c, int lim);

/**
 * @brief Entry point that reads stdin and removes comments from the input.
 *
 * The function reads up to MAXLINE characters from standard input, invokes
 * the comment skipping routine to strip C-style comments, and prints the
 * cleaned result.
 *
 * @return Zero on successful completion.
 */
int main ()
{
	int i, c, max;
	max = MAXLINE;
	char input[MAXLINE];
	for (i = 0; i < max && (c = getchar ()) != EOF; ++i)
		{
			input[i] = c;
		}
	skipComments (input, max);

	printf ("\nSkipped Comments:\n%s\n", input);
	return 0;
}

// lim must be larger than true size to allow for conversion and extra chars
// TODO: add in a column tracker that accounts for newlines
// TODO: figure out why theres trailing dirty characters in s[]
