#include "gnl/get_next_line.h"
#include "../error/result.h"

// data
#include "../data/i32x2.h"
#include "../data/i32u32.h"
#include "../data/vec2d_64.h"

#include <limits.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>

// for test
#include <stdio.h>

// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
#define Z_COLOR_WORD_MAX_LENGTH 23
typedef char t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

#define HEX_CHAR_TABLE_LENGTH 16
#define HEX_CHAR_TABLE "0123456789abcdef"


t_u32x2 colorcode2uint32(char *str);
int32_t str2int(char *str);

bool is_space(char c)
{
	return (
			c == ' ' ||
			c == '	'||
			c == '\n'
	);
}

bool is_comma(char c)
{
	return (
			c == ','
	);
}

/// wordの個数を判別する
int32_t count_word(char *str, bool (*is_delimiter)(char))
{
	int32_t w;
	bool flag;
	bool delim;

	w = 0;
	flag = false;
	while (*str != '\0')
	{
		delim = is_delimiter(*str);
		if (delim && flag)
			flag = false;
		else if (!delim && !flag)
		{
			w += 1;
			flag = true;
		}
		str++;
	}
	return (w);
}

/// 返り値はエラーコード
/// 
/// char *str           一行分のデータ
/// t_z_color_word word ワードデータの格納先
/// uint32_t x          x座標
/// bool (*is_delimiter)(char) 区切り文字の定義
enum e_result get_z_color_word(\
	char *str,\
	t_z_color_word word,\
	uint32_t x,\
	bool (*is_delimiter)(char)
)
{
	int32_t i;
	uint32_t w;
	bool flag;

	i = 0;
	w = 0;
	flag = false;
	while (*str != '\0')
	{
		if (is_delimiter(*str) && flag)
		{
			flag = false;
			w += 1;
		}
		else if (!is_delimiter(*str) && !flag)
			flag = true;
		if (flag && w == x && i < Z_COLOR_WORD_MAX_LENGTH - 1) // null文字ぶん引く
			word[i++] = *str;
		str++;
	}
	if (Z_COLOR_WORD_MAX_LENGTH < i)
		return (e_result_load_err);
	word[i] = '\0'; // 最大の場合iは23
	return (e_result_ok);
}

t_i32x2 get_mapsize(char *filename)
{	
	int fd;
	char	*buf;
	t_i32x2 counter; // (x, y)

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (encode_i32x2(-1, e_result_io_err));
	counter = encode_i32x2(0, 0);
	while (true)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (decode_int_x(counter) != 0 && \
		decode_int_x(counter) != count_word(buf,is_space))
			return (free(buf), encode_i32x2(-1, e_result_load_err));
		else if (count_word(buf,is_space) != 0)
			counter = encode_i32x2(count_word(buf,is_space), decode_int_y(counter));
		counter = t_i32x2_add(counter, encode_i32x2(0, 1));
		free(buf);
	}
	return (close(fd), counter);
}


/// ```
/// -123,0x00000000
/// ```
/// のような文字列を
/// ```
/// t_i32u32(-123, 0);
/// ```
/// を返すような関数
t_i32u32 z_color2t_i32u32(t_z_color_word zcolor)
{
	t_i32u32 r;
	int32_t countofwords;
	t_z_color_word word;
	t_u32x2 color;

	countofwords = count_word(zcolor ,is_comma);
	get_z_color_word(zcolor, word, 0, is_comma);
	r = encode_i32u32(
		str2int(word),
		0x00ffffff
	);
	if (countofwords == 2)
	{

		get_z_color_word(zcolor, word, 1,is_comma);
		color = colorcode2uint32(word);
		if (decode_uint_x(color) == e_result_ok)
			r = encode_i32u32(
				decode_iu_x(r),
				decode_uint_y(color)
			);
		else
		{
			// error TODO
			printf("error in  z_color2t_i32u32\n");
		}
	}
	else if (countofwords == 1)
	{
		// pass
	}
	else
	{
		// error TODO
		return (e_result_load_err);
	}
	return (r);
}


/// 16進数に使われる文字のみ受け付けるかどうか
bool is_hexchar(char c)
{
	return (
		'0' <= c || c <= '9' || 
		'a' <= c || c <= 'f'
	);
}

bool is_decimalchar(char c)
{
	return (
		'0' <= c || c <= '9'
	);
}

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
		return (encode_u32x2(e_result_load_err, 0));
	if (*str++ != 'x')
		return (encode_u32x2(e_result_load_err, 0));
	r = 0;
	while (*str != '\0')
	{
		if (is_hexchar(*str))
			r = 0x10 * r + get_hex_index(*str);
		else
			return (encode_u32x2(e_result_load_err, 0));
		str++;
	}
	return (encode_u32x2(e_result_ok, r));
}


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


/// @param uint32_t y      y座標
/// @param t_i32x2 mapsize (width, height)
/// @param char *buf       一行のデータ
/// @param vec2d_64 arr    整形後のデータを格納する部分
int set_row(uint32_t y, t_u32x2 mapsize, char *buf, vec2d_64 arr)
{
	uint32_t x;
	union u_64_elem a;
	t_z_color_word word;

	x = 0;
	while (x < decode_uint_x(mapsize))
	{
		get_z_color_word(buf, word, x, is_space);
		a.i32u32 = z_color2t_i32u32(word);
		set_vec2d_elem(arr, x, y, a);
		x += 1;
	}
	return (0);
}

 enum e_result load_map(vec2d_64 arr, char *filename)
 {
 	int fd;
 	char	*buf;
 	t_u32x2 counter; // (dx, dy)

 	fd = open(filename, O_RDONLY);
 	if (fd == -1)
 		return (e_result_io_err);
 	counter = encode_u32x2(0, 0);
 	while (decode_uint_y(counter) < decode_uint_y(get_shape(arr)))
 	{
 		buf = get_next_line(fd);
 		if (buf == NULL)
 			break ;
		set_row(decode_uint_y(counter), get_shape(arr), buf, arr);
 		free(buf);
 		counter = t_u32x2_add(counter, encode_u32x2(0, 1));
 	}
 	return (close(fd), e_result_ok);
 }

///
enum e_result alocate_memory_for_map(vec2d_64 *arr, char *filename)
{
	t_u32x2 mapsize;

	mapsize = get_mapsize(filename);
        *arr = init_vec2d_64(decode_uint_x(mapsize), decode_uint_y(mapsize)); // allocation occureda
												
	printf("memory allocated\n");
	load_map(*arr, filename);

	printf("loaded\n");
	if (*arr == NULL)
		printf("Error!");
	return (e_result_ok);
}
