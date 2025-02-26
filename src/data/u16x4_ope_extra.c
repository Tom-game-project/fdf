/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16x4_ope_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:07 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:30:21 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "u16x4.h"

/// スケールを変換します
t_u8x4	conv_u16x4_to_u8x4(t_u16x4 data)
{
	return (en_u8x4(
			(uint8_t)(de_u16x4_a(data) >> 8), \
			(uint8_t)(de_u16x4_b(data) >> 8), \
			(uint8_t)(de_u16x4_c(data) >> 8), \
			(uint8_t)(de_u16x4_d(data) >> 8)
		)
	);
}

t_u16x4	conv_u8x4_to_u16x4(t_u8x4 data)
{
	return (en_u16x4(
			(uint16_t)(de_u8x4_a(data) << 8), \
			(uint16_t)(de_u8x4_b(data) << 8), \
			(uint16_t)(de_u8x4_c(data) << 8), \
			(uint16_t)(de_u8x4_d(data) << 8)
		)
	);
}
