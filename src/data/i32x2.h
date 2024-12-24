#ifndef I32X2_H
#define I32X2_H

#include <stdint.h>

// # t_i32x2
/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |  int x  |  int y  |
typedef uint64_t t_i32x2;

t_i32x2 encode_i32x2(int32_t x, int32_t y);
int32_t decode_int_x(t_i32x2 data);
int32_t decode_int_y(t_i32x2 data);

// 演算
t_i32x2 t_i32x2_add(t_i32x2 a, t_i32x2 b);
t_i32x2 t_i32x2_sub(t_i32x2 a, t_i32x2 b);
t_i32x2 t_i32x2_mul(t_i32x2 a, t_i32x2 b);
int32_t t_i32x2_dot(t_i32x2 a,t_i32x2 b);
t_i32x2 t_i32x2_scalar(int32_t a, t_i32x2 b);

#endif
