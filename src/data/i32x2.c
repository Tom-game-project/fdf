/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32x2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:03 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:27:04 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include "i32x2.h"

// ======================= signed int =======================

t_i32x2 en_i32x2(int32_t x, int32_t y)
{
	return ((t_i32x2) ((uint64_t) x << 32) | (uint32_t)y);
}

int32_t de_int_x(t_i32x2 data)
{
	return ((int32_t) (data >> 32));
}

int32_t de_int_y(t_i32x2 data)
{
	return ((int32_t) (data & 0xFFFFFFFF));
}

t_i32x2 t_i32x2_add(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) + de_int_x(b),
		de_int_y(a) + de_int_y(b)
	));
}

t_i32x2 t_i32x2_sub(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) - de_int_x(b),
		de_int_y(a) - de_int_y(b)
	));
}

t_i32x2 t_i32x2_mul(t_i32x2 a,t_i32x2 b)
{
	return (en_i32x2(
		de_int_x(a) * de_int_x(b),
		de_int_y(a) * de_int_y(b)
	));
}

int32_t t_i32x2_dot(t_i32x2 a,t_i32x2 b)
{
	return (
		de_int_x(a) * de_int_x(b) +\
		de_int_y(a) * de_int_y(b)
	);
}

int32_t t_i32x2_max(t_i32x2 a)
{
	if (de_int_x(a) < de_int_y(a))
		return (de_int_y(a));
	else
		return (de_int_x(a));
}


bool t_i32x2_eq(t_i32x2 a,t_i32x2 b)
{
	return (
		de_int_x(a) == de_int_x(b) &&
		de_int_y(a) == de_int_y(b)
	);
}

/// 定数倍
t_i32x2 t_i32x2_scalar(int32_t a, t_i32x2 b)
{
	return (en_i32x2(a * de_int_x(b), a * de_int_y(b)));
}
