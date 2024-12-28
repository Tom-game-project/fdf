/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u8x4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:25 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:27:26 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u8x4.h"
#include <stdint.h>
#include <stdbool.h>


/// # t_u8x4
/// |---------- 32bit ----------|
/// | 8bit | 8bit | 8bit | 8bit |
///
typedef uint32_t t_u8x4;

t_u8x4 en_u8x4(
	uint8_t a,
	uint8_t b,
	uint8_t c,
	uint8_t d
)
{
	return (
		(t_u8x4)
		(
			 ((uint32_t) a << 24) |
			 ((uint32_t) b << 16) |
			 ((uint32_t) c << 8) |
			 ((uint32_t) d)
		)
	);
}


uint8_t de_u8x4_a(t_u8x4 data)
{
	return ((uint8_t) (data >> 24));
}

uint8_t de_u8x4_b(t_u8x4 data)
{
	return ((uint8_t) (data >> 16) & 0xFFFFFFFF);
}

uint8_t de_u8x4_c(t_u8x4 data)
{
	return ((uint8_t) (data >> 8) & 0xFFFFFFFF);
}

uint8_t de_u8x4_d(t_u8x4 data)
{
	return ((uint8_t) (data & 0xFFFFFFFF));
}

t_u8x4 t_u8x4_add(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) + de_u8x4_a(b),
			de_u8x4_b(a) + de_u8x4_b(b),
			de_u8x4_c(a) + de_u8x4_c(b),
			de_u8x4_d(a) + de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_sub(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) - de_u8x4_a(b),
			de_u8x4_b(a) - de_u8x4_b(b),
			de_u8x4_c(a) - de_u8x4_c(b),
			de_u8x4_d(a) - de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_mul(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) * de_u8x4_a(b),
			de_u8x4_b(a) * de_u8x4_b(b),
			de_u8x4_c(a) * de_u8x4_c(b),
			de_u8x4_d(a) * de_u8x4_d(b)
		)
	);
}

t_u8x4 t_u8x4_div(t_u8x4 a, t_u8x4 b)
{
	return (
		en_u8x4(
			de_u8x4_a(a) / de_u8x4_a(b),
			de_u8x4_b(a) / de_u8x4_b(b),
			de_u8x4_c(a) / de_u8x4_c(b),
			de_u8x4_d(a) / de_u8x4_d(b)
		)
	);
}


