#ifndef I32U32_H
#define I32U32_H

#include <stdint.h>

// # t_i32u32
/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |  int x  |  uint y |
typedef uint64_t t_i32u32;


t_i32u32 encode_i32u32(int32_t x, uint32_t y);
int32_t decode_iu_x(t_i32u32 data);
uint32_t decode_iu_y(t_i32u32 data);

#endif
