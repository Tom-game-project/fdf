/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:53 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 18:02:18 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get next line
#include "gnl/get_next_line.h"

// error enum
#include "../error/result.h"

// data
#include "../data/i32u32.h"
#include "../data/i32x2.h"
#include "../data/vec2d_64.h"
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/stat.h>

// for test
#include "loader_helper.h"
#include <stdio.h>
#include <unistd.h>

/// 返り値はエラーコード
///
/// char *str           一行分のデータ
/// t_z_color_word word ワードデータの格納先
/// uint32_t x          x座標
/// bool (*is_delimiter)(char) 区切り文字の定義
enum e_result	get_z_color_word(char *str, t_z_color_word word, uint32_t x,
		bool (*is_delimiter)(char))
{
	int32_t		i;
	uint32_t	w;
	bool		flag;

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
		if (flag && w == x && i < Z_COLOR_WORD_MAX_LENGTH - 1)
			word[i++] = *str;
		str++;
	}
	if (Z_COLOR_WORD_MAX_LENGTH < i)
		return (e_result_load_err);
	word[i] = '\0';
	return (e_result_ok);
}

t_i32x2	get_mapsize(char *filename, enum e_result *err)
{
	int		fd;
	char	*buf;
	t_i32x2	counter;

	fd = open(filename, O_RDONLY);
	*err = (fd == -1) * e_result_io_err;
	if (fd == -1)
		return (en_i32x2(-1, e_result_io_err));
	counter = en_i32x2(0, 0);
	while (true)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (de_int_x(counter) != 0 && de_int_x(counter) != count_word(buf,
				is_space))
			*err = e_result_load_err;
		else if (count_word(buf, is_space) != 0)
			counter = en_i32x2(count_word(buf, is_space), de_int_y(counter));
		counter = t_i32x2_add(counter, en_i32x2(0, 1));
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
t_i32u32	z_color2t_i32u32(t_z_color_word zcolor, int *err)
{
	t_i32u32		r;
	int32_t			countofwords;
	t_z_color_word	word;
	t_u32x2			color;

	countofwords = count_word(zcolor, is_comma);
	get_z_color_word(zcolor, word, 0, is_comma);
	r = en_i32u32(str2int(word), 0x00ffffff);
	*err = 0;
	if (countofwords == 2)
	{
		get_z_color_word(zcolor, word, 1, is_comma);
		color = colorcode2uint32(word);
		if (de_uint_x(color) == e_result_ok)
			r = en_i32u32(de_iu_x(r), de_uint_y(color));
		else
			*err = 1;
	}
	else if (countofwords == 1)
		return (r);
	else
		return (e_result_load_err);
	return (r);
}

/// @param uint32_t y      y座標
/// @param t_i32x2 mapsize (width, height)
/// @param char *buf       一行のデータ
/// @param vec2d_64 arr    整形後のデータを格納する部分
enum e_result	set_row(uint32_t y, t_u32x2 mapsize, char *buf, vec2d_64 arr)
{
	uint32_t		x;
	union u_64_elem	a;
	t_z_color_word	word;
	int				err;

	x = 0;
	while (x < de_uint_x(mapsize))
	{
		get_z_color_word(buf, word, x, is_space);
		a.i32u32 = z_color2t_i32u32(word, &err);
		if (err)
			return (e_result_load_err);
		set_vec2d_elem(arr, x, y, a);
		x += 1;
	}
	return (e_result_ok);
}

/// マップを読み込んで、配列にデータをセットする
enum e_result	load_map(vec2d_64 arr, char *filename)
{
	int				fd;
	char			*buf;
	t_u32x2			counter;
	enum e_result	err;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (e_result_io_err);
	counter = en_u32x2(0, 0);
	err = e_result_ok;
	while (de_uint_y(counter) < de_uint_y(get_shape(arr)))
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (set_row(de_uint_y(counter), get_shape(arr), buf,
				arr) == e_result_load_err)
			err = e_result_load_err;
		free(buf);
		counter = t_u32x2_add(counter, en_u32x2(0, 1));
	}
	return (close(fd), err);
}
