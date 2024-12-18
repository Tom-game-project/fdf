#ifndef ZCOLOR_H
#define ZCOLOR_H

#include <stdint.h>
#include <limits.h>

/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |    z    |  color  |
typedef uint64_t t_zcolor;

t_zcolor encode_zcolor(uint32_t z, uint32_t color);
uint32_t decode_z(t_zcolor data);
uint32_t decode_color(t_zcolor data);

#endif
