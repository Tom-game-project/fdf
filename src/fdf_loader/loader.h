#ifndef LOADER_H
#define LOADER_H

#include <stdint.h>
#include <stdbool.h>

uint32_t count_word(char *str, bool (*is_delimiter)(char));

#endif

