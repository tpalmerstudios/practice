#ifndef STORE_H
#define STORE_H

typedef struct Store Store;

/* Creation / Destruction */
Store *store_create(void);
void   store_destroy(Store *store);

/* Mutation */
int store_insert(Store *store, const char *key, const char *value);

/* Lookup */
const char *store_get(const Store *store, const char *key);

/* Iteration */
typedef void (*store_iter_fn)(
    const char *key,
    const char *value,
    void *user_data
);

void store_iterate(
    const Store *store,
    store_iter_fn fn,
    void *user_data
);

#endif

