#ifndef LOADER_H
#define LOADER_H

#include <stdint.h>
#include <stdbool.h>
#include "../error/result.h"

uint32_t count_word(char *str, bool (*is_delimiter)(char));
enum e_result load_map(char *filename);

#endif

