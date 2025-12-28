#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#define CTRL_KEY(k) ((k) & 0x1f)

struct editorCongig
{
	int screenrows;
	int screencols;
	struct termios orig_termios;
};

struct editorCongig E;

void
die (const char *s)
{
	write (STDOUT_FILENO, "\x1b]2J", 4);
	write (STDOUT_FILENO, "\x1b]H", 3);

	perror (s);
	exit (1);
}

void
disableRawMode ()
{
	if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1) die ("tcsetattr");
}

void
enableRawMode ()
{
	if (tcgetattr (STDIN_FILENO, &E.orig_termios) == -1) die ("tcgetattr");
	atexit (disableRawMode);

	struct termios raw = E.orig_termios;

	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw.c_iflag &= ~(IXON | ICRNL);
	raw.c_oflag &= ~(OPOST);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;

	if (tcsetattr (STDIN_FILENO, TCSAFLUSH, &raw) == -1) die ("tcsetattr");
}

char
editorReadKey ()
{
	int nread;
	char c;
	while ((nread = read (STDIN_FILENO, &c, 1)) != 1)
		{
			if (nread == -1 && errno != EAGAIN) die ("read");
		}
	return c;
}

int
getWindowSize (int *rows, int *cols)
{
	struct winsize ws;
	if (1 || ioctl (STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
		{
			if (write (STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12) return -1;
			editorReadKey ();
		}
	else
		{
			*cols = ws.ws_col;
			*rows = ws.ws_row;
			return 0;
		}
	return 0;
}

void
editorProcessKeypress ()
{
	char c = editorReadKey ();
	switch (c)
		{
		case CTRL_KEY ('q'):
			write (STDOUT_FILENO, "\x1b[2J", 4);
			write (STDOUT_FILENO, "\x1b[H", 3);
			exit (0);
			break;
		}
}

void
editorDrawRows ()
{
	int y;
	for (y = 0; y < E.screenrows; y++)
		{
			write (STDOUT_FILENO, "~\r\n", 3);
		}
}

void
editorRefreshScreen ()
{
	write (STDIN_FILENO, "\x1b[2J", 4);
	write (STDIN_FILENO, "\x1b[H", 3);
	editorDrawRows ();
	write (STDOUT_FILENO, "\x1b[H", 3);
}

void
initEditor ()
{
	if (getWindowSize (&E.screenrows, &E.screencols) == -1) die ("getWindowSize");
}

int
main (void)
{
	enableRawMode ();
	initEditor ();

	while (1)
		{
			editorRefreshScreen ();
			editorProcessKeypress ();
		}

	return 0;
}
