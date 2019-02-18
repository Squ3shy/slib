#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "hashtable.h"
#include "string_utils.h"

void procwenviron(struct hashtable_t *env) {
    int *v1 = (int *)hashtable_find(env, hash_string("key1"));
    int *v2 = (int *)hashtable_find(env, hash_string("key2"));
    char **nv = (char **)hashtable_find(env, hash_string("name"));

    printf("Values in procedure: %d, %d, %s\n", *v1, *v2, *nv);
}

int main(int argc, char *argv[]) {
    struct hashtable_t env = hashtable_new(1024);
    char *k1 = copy_string("key1");
    int v1 = 10;
    char *k2 = copy_string("key2");
    int v2 = 1234;
    char *nk = copy_string("name");
    char *nv = copy_string("Sean McCain");

    hashtable_put(&env, hash_string(k1), &v1);
    hashtable_put(&env, hash_string(k2), &v2);
    hashtable_put(&env, hash_string(nk), &nv);

    procwenviron(&env);

    hashtable_free(&env);
    free(k1);
    free(k2);
    free(nk);
    free(nv);
}
