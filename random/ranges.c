#include <float.h>
#include <limits.h>
#include <stdio.h>

int
main ()
{
	printf ("Bool Width: %d\n", BOOL_WIDTH);
	printf ("Bool Max: %d\n", BOOL_MAX);
	printf ("Char Bit Width of Byte: %d\n", CHAR_BIT);
	printf ("Max Bytes of Multi Byte Char: %d\n", MB_LEN_MAX);
	printf ("Char Width: %d\n", CHAR_WIDTH);
	printf ("Char Min Value: %d\n", CHAR_MIN);
	printf ("Char Max Value: %d\n", CHAR_MAX);

	printf ("Signed Char Width: %d\n", SCHAR_WIDTH);
	printf ("Short Width: %d\n", SHRT_WIDTH);
	printf ("Int Width: %d\n", INT_WIDTH);
	printf ("Long Width: %d\n", LONG_WIDTH);
	printf ("Long Long Width: %d\n", LLONG_WIDTH);

	printf ("Signed Char Min: %d\n", SCHAR_MIN);
	printf ("Short Min: %d\n", SHRT_MIN);
	printf ("Int Min: %d\n", INT_MIN);
	printf ("Long Min: %d\n", LONG_MIN);
	printf ("Long Long Min: %d\n", LLONG_MIN);

	printf ("Signed Char Max: %d\n", SCHAR_MAX);
	printf ("Short Max: %d\n", SHRT_MAX);
	printf ("Int Max: %d\n", INT_MAX);
	printf ("Long Max: %d\n", LONG_MAX);
	printf ("Long Long Max: %d\n", LLONG_MAX);

	printf ("\nUnsigned Chars\n");
	printf ("Unsigned Char Width: %d\n", UCHAR_WIDTH);
	printf ("Unsigned Short Width: %d\n", USHRT_WIDTH);
	printf ("Unsigned Int Width: %d\n", UINT_WIDTH);
	printf ("Unsigned Long Width: %d\n", ULONG_WIDTH);
	printf ("Unsigned Long Long Width: %d\n", ULLONG_WIDTH);

	printf ("Unsigned Char Max: %d\n", UCHAR_MAX);
	printf ("Unsigned Short Max: %d\n", USHRT_MAX);
	printf ("Unsigned Int Max: %d\n", UINT_MAX);
	printf ("Unsigned Long Max: %d\n", ULONG_MAX);
	printf ("Unsigned Long Long Max: %d\n", ULLONG_MAX);

	printf ("Float Decimals: %d\n", FLT_DECIMAL_DIG);
	printf ("Double Decimals: %d\n", DBL_DECIMAL_DIG);
	printf ("Long Double Decimals: %d\n", LDBL_DECIMAL_DIG);
	printf ("Float Min: %d\n", FLT_MIN);
	printf ("Double Min: %d\n", DBL_MIN);
	printf ("Long Double Min: %d\n", LDBL_MIN);
	printf ("Float Max: %d\n", FLT_MAX);
	printf ("Double Max: %d\n", DBL_MAX);
	printf ("Long Double Max: %d\n", LDBL_MAX);
	return 0;
}
