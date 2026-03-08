/************************************************
 * This is the example used by the `getopt`
 * manpage. Initially, I will type it from
 * scratch. Then I will adapt it into more use
 * cases
 * *********************************************/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
	int c;
	int digit_optind = 0;

	while (1)
		{
			// Tells where we are in argv. ensures we are at least at 1
			int this_option_optind = optind ? optind : 1;
			int option_index = 0;

			static struct option long_options[] = {
				{ "add", required_argument, 0, 0 },
				{ "append", no_argument, 0, 0 },
				{ "delete", required_argument, 0, 0 },
				{ "verbose", no_argument, 0, 0 },
				{ "create", required_argument, 0, 'c' },
				{ "file", required_argument, 0, 0 },
				{ 0, 0, 0, 0 } };

			c = getopt_long (argc, argv,
							 "abc:d:012",
							 long_options,
							 &option_index);

			if (c == -1)
				break;

			switch (c)
				{
				case 0:
					print ("option %s", long_options[option_index].name);
					if (optarg)
						printf (" with arg %s", optarg);
					printf ("\n");
					break;
				case '0':
				case '1':
				case '2':
					if (digit_optind != 0 && digit_optind != this_option_optind)
						printf ("digits occur in two different argv-elements.\n");
					digit_optind = this_option_optind;
					printf ("option %c\n", c);
					break;
				case 'a':
					break;
				case 'b':
					break;
				case 'c':
					break;
				case 'd':
					break;
				case '?':
					break;
				}
		}
}
