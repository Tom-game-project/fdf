#include <stdint.h>
#include <limits.h>
#include "zcolor.h"

/// 32bitの色情報、高さ情報をエンコードします
t_zcolor encode(uint32_t z, uint32_t color)
{
	t_zcolor u;

	u = (uint64_t)z << 32;
	u += color;
	return (u);
}

uint32_t decode_z(t_zcolor data)
{
	uint32_t r;

	r = (uint32_t) (data >> 32);
	return (r);
}

uint32_t decode_color(t_zcolor data)
{
	uint32_t r;
	t_zcolor u;

	u = data << 32;
	r = (uint32_t) (u >> 32);
	return (r);
}
