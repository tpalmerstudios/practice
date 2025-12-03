#include <stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getlines();
void copy();
void reverse();

int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getlines()) > 0) {
	if (len > max) {
	    max = len;
	    copy();
	}
    }
    if (max > 0) {
	printf("Longest %d: %s\n", max, longest);
	reverse();
	printf("Reversed: %s\n", longest);
    }
    return 0;
}

int getlines() {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	line[i] = c;
    if (c == '\n') {
	line[i] = c;
	++i;
    }
    line[i] = '\0';
    return i;
}

void copy() {
    int i = 0;
	extern char line [], longest [];
    while ((longest[i] = line[i]) != '\0') ++i;
}

void reverse() {
	extern int max;
	extern char longest [];
    char t[max];
    int i, j;
    i = max - 2;
    for (j = 0; j < max; ++j) {
	t[j] = longest[i];
	--i;
    }
    t[max - 1] = '\0';
    for (i = 0; i < max; ++i) longest[i] = t[i];
}
