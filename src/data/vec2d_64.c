/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:46 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:24:28 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../error/result.h"
#include "i32x2.h"
#include "u32x2.h"
#include "vec2d_64.h"
#include <stdint.h>
#include <stdlib.h>

// test functions
#include <stdio.h>

/// `vec<vec<t_64_elem>>`
///
/// 実態は(width * height + 1)の長さのu64を格納した配列
/// 使用している関数
/// - malloc
vec2d_64	init_vec2d_64(uint32_t width, uint32_t height)
{
	vec2d_64	r;

	r = (t_64_elem *)malloc(sizeof(t_64_elem) * (width * height
				+ DATA_PADDING));
	if (r == NULL)
		return (NULL);
	r[SHARP].u32x2 = en_u32x2(width, height);
	return (r);
}

// data[y][x]
t_64_elem	get_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y)
{
	uint32_t	width;

	width = de_uint_x(data[SHARP].u32x2);
	return (data[width * y + x + DATA_PADDING]);
}

/// data[y][x] = i;
enum e_result	set_vec2d_elem(vec2d_64 data, uint32_t x, uint32_t y,
		t_64_elem i)
{
	uint32_t	width;
	uint32_t	height;

	width = de_uint_x(data[SHARP].u32x2);
	height = de_uint_y(data[SHARP].u32x2);
	if (x < width && y < height)
		data[width * y + x + DATA_PADDING] = i;
	else
		return (e_result_index_out_of_range_err);
	return (e_result_ok);
}

/// 二次元配列の形状を取得
t_u32x2	get_shape(vec2d_64 arr)
{
	return (arr[0].u32x2);
}

enum e_result	vec2d_map(vec2d_64 arr, t_64_elem (*func)(t_64_elem a))
{
	t_u32x2		shape;
	uint32_t	i;

	i = DATA_PADDING;
	shape = get_shape(arr);
	while (i <= de_uint_x(shape) * de_uint_y(shape))
	{
		arr[i] = func(arr[i]);
		i += 1;
	}
	return (e_result_ok);
}
