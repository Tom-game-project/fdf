#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "../data/u32x2.h"
#include "../error/result.h"

#include "loader_helper.h"

#define HEX_CHAR_TABLE_LENGTH 16
#define HEX_CHAR_TABLE "0123456789abcdef"
#define LHEX_CHAR_TABLE "0123456789ABCDEF"

/// # loader_helper01
/// 
/// ここには、数字文字列をint,hexに変換する関数
/// fdfフォーマットで書かれた最小単位の情報を解釈する関数
///

/// unsafe 
/// この関数では必ずdstのサイズを認識した上で実行してください
/// また、この関数では最後は'\0'文字で埋められません
static bool set_str(char *dst, char *fr)
{
	while (*fr != '\0')
		*dst++ = *fr++;
	return (0);
}

///
uint32_t get_hex_index(char c)
{
	char hex_table[HEX_CHAR_TABLE_LENGTH];
	int i;

	set_str(hex_table, HEX_CHAR_TABLE);
	i = 0;
	while (i < HEX_CHAR_TABLE_LENGTH)
	{
		if (c == hex_table[i])
			return (i);
		i += 1;
	}
	set_str(hex_table, LHEX_CHAR_TABLE);
	i = 0;
	while (i < HEX_CHAR_TABLE_LENGTH)
	{
		if (c == hex_table[i])
			return (i);
		i += 1;
	}
	return (0); // unreachable 
}

/// 入力は以下のようなもの
/// ```
/// 0xf1af
///
/// 0x00000000
/// 0xffffffff
/// ```
///
/// return t_u32x2(error_code, data)
t_u32x2 colorcode2uint32(char *str)
{
	uint32_t r;

	if (*str++ != '0')
		return (en_u32x2(e_result_load_err, 0));
	if (*str++ != 'x')
		return (en_u32x2(e_result_load_err, 0));
	r = 0;
	while (*str != '\0')
	{
		if (is_hexchar(*str))
			r = 0x10 * r + get_hex_index(*str);
		else
			return (en_u32x2(e_result_load_err, 0));
		str++;
	}
	return (en_u32x2(e_result_ok, r));
}

/// 数字文字列をin32_t型に変換する
int32_t str2int(char *str)
{
	int32_t sign;
	int32_t r;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str += 1;
	}
	r = 0;
	while (*str != '\0')
	{
		if (is_decimalchar(*str))
			r = 10 * r + (*str - '0');
		else
			printf("str2int Error!\n"); // TODO
		str++;
	}
	return (sign * r);
}

