#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include "types.h"

char *copy_string_wlen(const char *string, u64 length);
char *copy_string(const char *string);

u64 hash_string_wlen(const char *string, u64 length);
u64 hash_string(const char *string);

#endif
