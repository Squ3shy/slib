#include "hashtable.h"

#include <stdlib.h>
#include <string.h>

struct hashtable_t hashtable_new(u64 count) {
    struct hashtable_t self;
    self.entries = array_new(sizeof(struct hashentry_t));
    return self;
}

int hashtable_contains(struct hashtable_t *self, u64 hash, u64 *location) {
    for (u64 i = 0; i < self->entries.count; i++) {
        struct hashentry_t entry = *(struct hashentry_t *)array_get(&self->entries, i);
        if (entry.hash == hash) {
            *location = i;
            return 1;
        }
    }

    return 0;
}

void hashtable_put(struct hashtable_t *self, u64 hash, void *value) {
    u64 location;
    int found = hashtable_contains(self, hash, &location);

    if (found) {
        struct hashentry_t entry = *(struct hashentry_t *)array_get(&self->entries, location);
        entry.value = value;
        array_set(&self->entries, location, &entry);
    } else {
        struct hashentry_t entry;
        entry.hash = hash;
        entry.value = value;

        array_add(&self->entries, &entry);
    }
}

void *hashtable_find(struct hashtable_t *self, u64 hash) {
    for (u64 i = 0; i < self->entries.count; i++) {
        struct hashentry_t entry = *(struct hashentry_t *)array_get(&self->entries, i);

        if (entry.hash == hash) return entry.value;
    }

    return NULL;
}

void hashtable_free(struct hashtable_t *self) {
    array_free(&self->entries);
}
