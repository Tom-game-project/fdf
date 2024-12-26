#ifndef PRINT_DATA_H
#define PRINT_DATA_H

#include "i32x2.h"
#include "u32x2.h"
#include "i32u32.h"
#include "u16x4.h"
#include "u8x4.h"
#include "vec2d_64.h"

int print_u32x2(t_u32x2 data);
int print_i32x2(t_i32x2 data);
int print_i32u32(t_i32u32 data);
int print_u16x4(t_u16x4 data);
int print_u8x4(t_u8x4 data);
//

int print_vec2d_elem_i32u64(vec2d_64 arr);

int print_vec2d_elem_i32x2(vec2d_64 arr);

#endif
