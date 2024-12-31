/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32x2_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:23:28 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:14:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "i32x2.h"

t_i32x2	t_i32x2_complex_mul(t_i32x2 a, t_i32x2 b)
{
	return (
		en_i32x2(
			de_int_x(a) * de_int_x(b) -\
			de_int_y(a) * de_int_y(b),
			de_int_x(a) * de_int_y(b) +\
			de_int_x(b) * de_int_y(a)
		)
	);
}
