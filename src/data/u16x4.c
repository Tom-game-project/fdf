/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16x4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:32 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 17:03:46 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include "u16x4.h"
#include "print_data.h"
#include "u8x4.h"


/// スケールを変換します
t_u8x4 conv_u16x4_to_u8x4(t_u16x4 data)
{
	return (en_u8x4(
			(uint8_t)(de_u16x4_a(data) >> 8), \
			(uint8_t)(de_u16x4_b(data) >> 8), \
			(uint8_t)(de_u16x4_c(data) >> 8), \
			(uint8_t)(de_u16x4_d(data) >> 8)
		)
	);
}

t_u16x4 conv_u8x4_to_u16x4(t_u8x4 data)
{
	return (en_u16x4(
			(uint16_t)(de_u8x4_a(data) << 8), \
			(uint16_t)(de_u8x4_b(data) << 8), \
			(uint16_t)(de_u8x4_c(data) << 8), \
			(uint16_t)(de_u8x4_d(data) << 8)
		)
	);
}

static int16_t int16_add(int16_t a, int16_t b)
{
	return (a + b);
}

static int16_t int16_sub(int16_t a, int16_t b)
{
	return (a - b);
}

// TODO
// color tools

t_u16x4 t_u16x4_map(t_u16x4 a, t_u16x4 b, int16_t (*func)(int16_t a, int16_t b))
{
	return (
		en_u16x4(
			func(de_u16x4_a(a), de_u16x4_a(b)), \
			func(de_u16x4_b(a), de_u16x4_b(b)), \
			func(de_u16x4_c(a), de_u16x4_c(b)), \
			func(de_u16x4_d(a), de_u16x4_d(b))
		)
	);
}

t_u16x4 t_u16x4_cal_color(t_u16x4 a, t_u16x4 b, t_u8x4 map)
{
	int16_t		(*func[2])(int16_t a, int16_t b);

	func[0] = int16_add;
	func[1] = int16_sub;
	return (
		en_u16x4(
			func[de_u8x4_a(map)](de_u16x4_a(a), de_u16x4_a(b)), \
			func[de_u8x4_b(map)](de_u16x4_b(a), de_u16x4_b(b)), \
			func[de_u8x4_c(map)](de_u16x4_c(a), de_u16x4_c(b)), \
			func[de_u8x4_d(map)](de_u16x4_d(a), de_u16x4_d(b))
		)
	);
}

t_u8x4 create_u16x4_bool_map(t_u16x4 a,t_u16x4 b, bool (*func)(int16_t a, int16_t b))
{
	return (
		en_u8x4(
			func(de_u16x4_a(a), de_u16x4_a(b)),
			func(de_u16x4_b(a), de_u16x4_b(b)),
			func(de_u16x4_c(a), de_u16x4_c(b)),
			func(de_u16x4_d(a), de_u16x4_d(b))
		)
	);
}
