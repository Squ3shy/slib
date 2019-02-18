#include "string_utils.h"

#include <stdlib.h>
#include <string.h>

char *copy_string_wlen(const char *string, u64 length) {
    char *result = (char *)malloc(sizeof(char) * length + 1);
    memcpy(result, string, length);
    result[length] = 0;

    return result;
}

char *copy_string(const char *string) {
    return copy_string_wlen(string, strlen(string));
}

u64 hash_string_wlen(const char *string, u64 length) {
    u64 result = 0;

    for (u64 i = 0; i < length; i++) {
        result ^= string[i] + 0x9e3779b9 + (result << 6) + (result >> 2);
    }

    return result;
}

u64 hash_string(const char *string) {
    return hash_string_wlen(string, strlen(string));
}
