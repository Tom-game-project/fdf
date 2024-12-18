#ifndef U32X2_H
#define U32X2_H

#include <stdint.h>
#include <limits.h>


/// # t_u32x2
/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |    x    |    y    |
typedef uint64_t t_u32x2;


t_u32x2 encode_u32x2(uint32_t x, uint32_t y);
uint32_t decode_x(t_u32x2 data);
uint32_t decode_y(t_u32x2 data);


// 2d


typedef t_u32x2 *vec2d_u32x2;
vec2d_u32x2 init_vec2d_u32x2(uint32_t width, uint32_t height);
t_u32x2 get_vec2d_u32x2_elem(vec2d_u32x2 data,uint32_t x, uint32_t y);
int set_vec2d_u32x2_elem(vec2d_u32x2 data, uint32_t x, uint32_t y, t_u32x2 i);

#endif
