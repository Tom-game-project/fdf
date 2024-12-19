#include "u32x2.h"
#include "vec2d_64.h"

#include <stdlib.h>
#include <stdint.h>


#define DATA_PADDING 1
#define SHARP 0

/// `vec<vec<t_64_elem>>`
///
/// 実態は(width * height + 1)の長さのu64を格納した配列
/// 使用している関数
/// - malloc
vec2d_64 init_vec2d_64(uint32_t width, uint32_t height)
{
	vec2d_64 r;

	r = (t_64_elem*) malloc (sizeof(t_64_elem) * (width * height + DATA_PADDING));
	if (r == NULL)
		return (NULL);
	r[SHARP].u32x2 = encode_u32x2(width, height);
	return (r);
}

// data[y][x]
t_64_elem get_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y)
{
	uint32_t width;

	width = decode_uint_x(data[SHARP].u32x2);
	return (data[width * y + x + DATA_PADDING]);
}

/// data[y][x] = i;
int set_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y, t_64_elem i)
{
	uint32_t width;
	uint32_t height;

	width = decode_uint_x(data[SHARP].u32x2);
	height = decode_uint_y(data[SHARP].u32x2);
	if (x < width && y < height)
		data[width * y + x + DATA_PADDING] = i;
	else
		return (1);
	return (0);
}
