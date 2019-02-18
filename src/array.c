#include "array.h"

#include <stdlib.h>
#include <string.h>

struct array_t array_new(u64 item_size) {
    struct array_t self;
    self.count = 0;
    self.cap = 1;
    self.item_size = item_size;
    self.items = malloc(self.item_size * self.cap);
    self.man_alloc = 0;

    return self;
}

void array_reserve(struct array_t *self, u64 count) {
    self->cap += count;

    void *copy = malloc(self->item_size * self->count);
    memcpy(copy, self->items, self->item_size * self->count);
    self->items = realloc(self->items, self->item_size * self->cap);
    memcpy(self->items, copy, self->item_size * self->count);
    free(copy);
}

void array_set(struct array_t *self, u64 index, void *item) {
    memcpy(self->items + self->item_size * index, item, self->item_size);
}

void array_insert(struct array_t *self, u64 index, void *item) {
    if (self->count + 1 > self->cap) {
        if (!self->man_alloc) {
            array_reserve(self, self->cap);
        } else {
            array_reserve(self, 1);
        }
    }

    array_set(self, index, item);
}

void array_add(struct array_t *self, void *item) {
    array_insert(self, ++self->count - 1, item);
}

void *array_get(struct array_t *self, u64 index) {
    return (char *)(self->items) + self->item_size * index;
}

void array_free(struct array_t *self) {
    free(self->items);
}
