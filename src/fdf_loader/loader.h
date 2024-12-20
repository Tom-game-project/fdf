#ifndef LOADER_H
#define LOADER_H

#include <stdint.h>
#include <stdbool.h>
#include "../error/result.h"
#include "../data/i32x2.h"

uint32_t count_word(char *str, bool (*is_delimiter)(char));
enum e_result load_map(char *filename);
t_i32x2 get_mapsize(char *filename);

#endif

