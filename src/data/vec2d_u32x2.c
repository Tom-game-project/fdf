#include "u32x2.h"
#include <stdlib.h>
#include <stdint.h>

#define DATA_PADDING 1
#define SHARP 0



/// `vec<vec<(x,y)>>`
/// 
/// 実態は(width * height + 1)の長さのu64を格納した配列
vec2d_u32x2 init_vec2d_u32x2(uint32_t width, uint32_t height)
{
	vec2d_u32x2 r;

	r = (t_u32x2 *)malloc (sizeof(t_u32x2) * (width * height + DATA_PADDING));
	if (r == NULL)
		return (NULL);
	r[SHARP] = encode_u32x2(width, height);
	return (r);
}

t_u32x2 get_vec2d_u32x2_elem(vec2d_u32x2 data,uint32_t x, uint32_t y)
{
	uint32_t width;
//	uint32_t height;

	width = decode_uint_x(data[SHARP]);
//	height = decode_y(data[SHARP]);
	return (data[width * y + x + DATA_PADDING]);
}

/// data[y][x] = i;
int set_vec2d_u32x2_elem(vec2d_u32x2 data, uint32_t x, uint32_t y, t_u32x2 i)
{
	uint32_t width;
	uint32_t height;

	width = decode_uint_x(data[SHARP]);
	height = decode_uint_y(data[SHARP]);
	if (x < width && y < height)
		data[width * y + x + DATA_PADDING] = i;
	else
		return (1);
	return (0);
}
