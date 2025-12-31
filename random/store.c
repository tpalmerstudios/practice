#include "store.h"
#include <stdlib.h>

struct Store
{
	size_t count;
	char *key;
	char *value;
	struct Store *next;
	struct Record *record;
};

struct Record
{
	char *song;
}

Store *
store_create (void)
{
	Store *s = malloc (sizeof *s);
	if (!s) return NULL;
	s->count return s;
}

void
store_destroy (Store *store)
{
	free (store);
}

int
store_insert (Store *store, const char *key, const char *value)
{
	store - iterate->value = &value;
}

const char *
store_get (const Store *store, const char *key)
{
	iterate
}

void
store_iterate (const Store *store, store_iter_fn fn, void *user_data)
{
}

typedef void (*store_iter_fn) (const char *key, const char *value, void *user_data);

