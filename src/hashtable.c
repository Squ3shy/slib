#include "hashtable.h"

#include <stdlib.h>
#include <string.h>

struct hashtable_t hashtable_new(u64 count) {
    struct hashtable_t self;

    self.count = count;
    self.pointer = 0;
    self.entries = (struct hashentry_t *)malloc(sizeof(struct hashentry_t) * self.count);

    return self;
}

int hashtable_contains(struct hashtable_t *self, u64 hash, u64 *location) {
    for (u64 i = 0; i < self->pointer; i++) {
        struct hashentry_t entry = self->entries[i];
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
        self->entries[location].value = value;
    } else {
        struct hashentry_t entry;
        entry.hash = hash;
        entry.value = value;

        self->entries[self->pointer++] = entry;
    }
}

void *hashtable_find(struct hashtable_t *self, u64 hash) {
    for (u64 i = 0; i < self->pointer; i++) {
        struct hashentry_t entry = self->entries[i];

        if (entry.hash == hash) return entry.value;
    }

    return NULL;
}

void hashtable_free(struct hashtable_t *self) {
    free(self->entries);
}
