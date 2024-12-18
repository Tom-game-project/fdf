#include <stdint.h>
#include <limits.h>
#include "zcolor.h"

/// 32bitの色情報、高さ情報をエンコードします
t_zcolor encode_zcolor(uint32_t z, uint32_t color)
{
	return ((t_zcolor) ((uint64_t)z << 32) + color);
}

/// 64bitの`t_zcolor`から`z`の情報を取り出します
uint32_t decode_z(t_zcolor data)
{
	return ((uint32_t) (data >> 32));
}

/// 64bitの`t_zcolor`から`color`の情報を取り出します
uint32_t decode_color(t_zcolor data)
{
	return ((uint32_t) ((data << 32) >> 32));
}
