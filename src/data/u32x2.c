/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32x2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:39 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 17:12:13 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "u32x2.h"

t_u32x2	t_u32x2_add(t_u32x2 a, t_u32x2 b)
{
	return (
		en_u32x2(
			de_uint_x(a) + de_uint_x(b),
			de_uint_y(a) + de_uint_y(b)
		)
	);
}

t_u32x2	t_u32x2_sub(t_u32x2 a, t_u32x2 b)
{
	return (
		en_u32x2(
			de_uint_x(a) - de_uint_x(b),
			de_uint_y(a) - de_uint_y(b)
		)
	);
}

t_u32x2	t_u32x2_mul(t_u32x2 a, t_u32x2 b)
{
	return (
		en_u32x2(
			de_uint_x(a) * de_uint_x(b),
			de_uint_y(a) * de_uint_y(b)
		)
	);
}

int32_t t_u32x2_dot(t_u32x2 a, t_u32x2 b)
{
	return (
		de_uint_x(a) * de_uint_x(b) + \
		de_uint_y(a) * de_uint_y(b)
	);
}
