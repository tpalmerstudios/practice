#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "text.h"

static void expect_string (const char *expected, const char *actual)
{
	assert (strcmp (expected, actual) == 0);
}

static void test_reverse_basic (void)
{
	char value[] = "hello";
	reverse (value, sizeof (value));
	expect_string ("olleh", value);
}

static void test_nextChar_found_and_missing (void)
{
	char value[] = "abcda";
	assert (nextChar (value, 1, 'a', sizeof (value)) == 4);
	assert (nextChar (value, 2, 'z', sizeof (value)) == 0);
}

static void test_isPrepend (void)
{
	char value[] = "abc";
	assert (isPrepend (value, 2, 'b', sizeof (value)) == 1);
	assert (isPrepend (value, 2, 'a', sizeof (value)) == 0);
	assert (isPrepend (value, -1, 'a', sizeof (value)) == -1);
}

static void test_isPostpend (void)
{
	char value[] = "abc";
	assert (isPostpend (value, 0, 'b', sizeof (value)) == 1);
	assert (isPostpend (value, 0, 'c', sizeof (value)) == 0);
	assert (isPostpend (value, 5, 'a', sizeof (value)) == -1);
}

static void test_detab_expands_tabs (void)
{
	char value[16] = "1\t2";
	detab (value, 4, sizeof (value));
	expect_string ("1   2", value);
}

static void test_skipComments_removes_comments_and_preserves_literals (void)
{
	char value[128] =
		"int a=1; // drop\nchar *s=\"//keep\"; /*block*/return 0; //tail\n";
	skipComments (value, sizeof (value));
	expect_string ("int a=1; \nchar *s=\"//keep\"; return 0; \n", value);
}

static void test_fold_wraps_at_whitespace (void)
{
	char value[64] = "wrap here words";
	fold (value, 6, sizeof (value));
	expect_string ("wrap\nhere\nwords", value);
}

static void test_fold_hyphenates_long_words (void)
{
	char value[64] = "abcdefgh";
	fold (value, 4, sizeof (value));
	expect_string ("ab -\nbc ", value);
}

static void test_entab_collapses_spaces (void)
{
	char value[32] = "        X"; // 8 spaces
	entab (value, 4, sizeof (value));
	expect_string ("\t\tX", value);
}

int main (void)
{
	puts ("Running reverse test...");
	test_reverse_basic ();
	puts ("Running nextChar tests...");
	test_nextChar_found_and_missing ();
	puts ("Running isPrepend tests...");
	test_isPrepend ();
	puts ("Running isPostpend tests...");
	test_isPostpend ();
	puts ("Running detab tests...");
	test_detab_expands_tabs ();
	puts ("Running skipComments tests...");
	test_skipComments_removes_comments_and_preserves_literals ();
	puts ("Running fold whitespace tests...");
	test_fold_wraps_at_whitespace ();
	puts ("Running fold hyphenation tests...");
	test_fold_hyphenates_long_words ();
	puts ("Running entab tests...");
	test_entab_collapses_spaces ();

	puts ("All text.h tests passed.");
	return 0;
}
