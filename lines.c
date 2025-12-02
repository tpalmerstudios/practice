#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int lim);

int main() {
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getlines(line, MAXLINE)) > 0) {
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    }
    if (max > 0)
	{
		printf("Longest %d: %s\n", max, longest);
		reverse (longest, max);
		printf("Reversed: %s\n", longest);
	}
    return 0;
}

int getlines(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}

void reverse(char s[], int lim) {
    char t[lim];
    int i, j;
	i = lim - 2;
    for (j = 0; j < lim; ++j) {
		t[j] = s[i];
		--i;
    }
	t [lim - 1] = '\0';
	for (i = 0; i < lim; ++i)
		s[i] = t[i];
}
