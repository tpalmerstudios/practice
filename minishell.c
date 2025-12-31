/*****************************************************
 * This was in "mini-shell-en-C" created by theo-p38
 * The repo was removed after I had modified this file.
 * I don't have access to the rest of the repo
 * ***************************************************/
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define NB_MAX_MOTS 30
#define MAXLENGTH 4096

#define UNUSED(x) (void) (x)

void
read_et_analyse_line (char *line, char *command[])
{
	*line = '\0';

	int i;

	while (fgets (line, MAXLENGTH, stdin) != NULL)
		if (feof (stdin))
			{
				printf ("\n");
				exit (0);
			}

	char *fWord = line;
	for (i = 0; *fWord && i < MAXWORD - 1; i++)
		{
			if (*fWord && !isspace (*fWord))
				{
					command[i] = fWord;
					while (!isspace (*fWord))
						fWord++;
					*fWord = '\0';
				}
			else
				while (*fWord && isspace (*fWord))
					fWord++;
		}
	command[i] = NULL;
}

void
affiche_invite (void)
{
	char *getPtr = get_current_dir_name ();
	if (!getPtr) exit (0);

	printf ("\n%s> ", strrchr (getPtr, '/') + 1);
	fflush (stdout);
	// must free
	free (getPtr);
}

void
traite_signal (int signal_recu)
{
	UNUSED (signal_recu);
	affiche_invite ();
}

void
initialiser_gestion_signaux (struct sigaction *sig)
{
	sig->sa_flags = SA_NOCLDSTOP;
	sigemptyset (&sig->sa_mask);

	// Signal Handler passed a pointer to a function
	sig->sa_handler = traite_signal;
	sigaction (SIGINT, sig, NULL);
}

int
runInternal (char *command[], int *error)
{
	struct internals
	{
		char selfExec = { "cd" };
		int count = 1;
	};
	int i;

	for (i = 0; i < count; i++)
	{
	}
	return 0;
}

void
execute_command (char *command[], struct sigaction *sig)
{
	int *errorCode;
	if (runInternal (command, errorCode))
		{
		}
}

void
execute_command (char *command[], struct sigaction *sig)
{
	if (!command[0]) return;

	/***********************
	 * My new structure
	 * if command 0 == internal func, execute in separate func
	 * else execute as described.
	 *
	 * ideally we add a path variable
	 * ********************/
	// lets create a list of internal functions we will handle and then execute them in a different
	// function cd shouldn't be done here
	else if (!strcmp (command[0], "cd"))
		{
			int argc = 0;
			while (command[argc])
				argc++;
			// How many parts of the command are there?

			if (argc == 1)
				{
					if (chdir (getenv ("HOME")) == -1)
						{
							perror ("mini-shell: cd");
						}
				}
			else if (argc == 2)
				{
					// Let's add in ~ expansion rather than assuming it's solo char
					if (strcmp (command[1], "~") == 0)
						{
							strcpy (command[1], getenv ("HOME"));
						}
					if (chdir (command[1]) == -1)
						{
							perror ("mini-shell: cd");
							if (errno == ENOENT)
								{
									fprintf (stderr, "Conseil : vÃ©rifiez que tous les "
													 "rÃ©pertoires du chemin existent\n");
								}
							else if (errno == EACCES)
								{
									fprintf (stderr, "Conseil : vÃ©rifiez que vous pouvez accÃ©der "
													 "Ã  tous les rÃ©pertoires du chemin\n");
								}
						}
				}
			else
				{
					// I think we could try to use the first arg rather than just failing
					fprintf (stderr, "Error: too many arguments\n");
				}
		}
	else
		{
			pid_t res_f;
			int statut;

			sig->sa_handler = SIG_IGN;
			sigaction (SIGINT, sig, NULL);

			res_f = fork ();
			// Child gets new.

			if (res_f == -1)
				{
					perror ("mini-shell: fork");
					exit (errno);
				}

			if (res_f == 0)
				{
					sig->sa_handler = SIG_DFL;
					sigaction (SIGINT, sig, NULL);

					if (execvp (command[0], command) == -1)
						{
							perror ("mini-shell: execvp");
							exit (errno);
						}
				}
			else
				{
					if (waitpid (res_f, &statut, 0) == -1)
						{
							perror ("mini-shell: waitpid");
							exit (errno);
						}

					sig->sa_handler = traite_signal;
					sigaction (SIGINT, sig, NULL);
				}
		}
}

int
main (void)
{
	char line[MAXLENGTH];
	char *command[NB_MAX_MOTS + 1];
	// stdlib defined
	struct sigaction m_sig;

	initialiser_gestion_signaux (&m_sig);

	while (true)
		{
			// Show prompt
			affiche_invite ();
			// Put commands into an array
			read_et_analyse_line (line, command);
			execute_command (command, &m_sig);
		}

	return EXIT_SUCCESS;
}
