/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16x4_encode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:24:12 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 18:24:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u16x4.h"

t_u16x4	en_u16x4(
	uint16_t a,
	uint16_t b,
	uint16_t c,
	uint16_t d
)
{
	return (
		(t_u16x4)
		(
			((uint64_t) a << 48) | \
			((uint64_t) b << 32) | \
			((uint64_t) c << 16) | \
			((uint64_t) d)
		)
	);
}
