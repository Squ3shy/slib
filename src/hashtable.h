#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "types.h"

struct hashentry_t {
    u64 hash;
    void *value;
};

struct hashtable_t {
    u64 count;
    u64 pointer;
    struct hashentry_t *entries;
};

struct hashtable_t hashtable_new(u64 count);
int hashtable_contains(struct hashtable_t *self, u64 hash, u64 *location);
void hashtable_put(struct hashtable_t *self, u64 hash, void *value);
void *hashtable_find(struct hashtable_t *self, u64 hash);
void hashtable_free(struct hashtable_t *self);

#endif
