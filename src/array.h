#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "types.h"

struct array_t {
    u64 count;
    u64 cap;
    u64 item_size;
    int man_alloc;
    void *items;
};

struct array_t array_new(u64 item_size);
void array_reserve(struct array_t *self, u64 count);
void array_set(struct array_t *self, u64 index, void *item);
void array_insert(struct array_t *self, u64 index, void *item);
void array_add(struct array_t *self, void *item);
void *array_get(struct array_t *self, u64 index);
void array_free(struct array_t *self);

#endif
