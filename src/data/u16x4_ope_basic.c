/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16x4_ope_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:24:15 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:21:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u16x4.h"

t_u16x4	t_u16x4_add(t_u16x4 a, t_u16x4 b)
{
	return (
		en_u16x4(
			de_u16x4_a(a) + de_u16x4_a(b), \
			de_u16x4_b(a) + de_u16x4_b(b), \
			de_u16x4_c(a) + de_u16x4_c(b), \
			de_u16x4_d(a) + de_u16x4_d(b)
		)
	);
}

t_u16x4	t_u16x4_sub(t_u16x4 a, t_u16x4 b)
{
	return (
		en_u16x4(
			de_u16x4_a(a) - de_u16x4_a(b),
			de_u16x4_b(a) - de_u16x4_b(b),
			de_u16x4_c(a) - de_u16x4_c(b),
			de_u16x4_d(a) - de_u16x4_d(b)
		)
	);
}

t_u16x4	t_u16x4_mul(t_u16x4 a, t_u16x4 b)
{
	return (
		en_u16x4(
			de_u16x4_a(a) * de_u16x4_a(b),
			de_u16x4_b(a) * de_u16x4_b(b),
			de_u16x4_c(a) * de_u16x4_c(b),
			de_u16x4_d(a) * de_u16x4_d(b)
		)
	);
}

t_u16x4	t_u16x4_div(t_u16x4 a, t_u16x4 b)
{
	return (
		en_u16x4(
			de_u16x4_a(a) / de_u16x4_a(b),
			de_u16x4_b(a) / de_u16x4_b(b),
			de_u16x4_c(a) / de_u16x4_c(b),
			de_u16x4_d(a) / de_u16x4_d(b)
		)
	);
}

t_u16x4	t_u16x4_div_scalar(t_u16x4 a, int16_t b)
{
	return (
		en_u16x4(
			de_u16x4_a(a) / b,
			de_u16x4_b(a) / b,
			de_u16x4_c(a) / b,
			de_u16x4_d(a) / b
		)
	);
}

