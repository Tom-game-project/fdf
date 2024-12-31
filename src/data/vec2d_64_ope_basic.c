/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2d_64_ope_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:27 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:31:49 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "i32x2.h"
#include "vec2d_64.h"
#include "stdint.h"
#include <stdint.h>
///  n 
/// w e
///  s


/// return t_i32x2(w, e);
t_i32x2	get_we(vec2d_64 arr)
{
	t_u32x2		shape;
	t_i32x2		r;
	uint32_t	i;
	int32_t		tmp;

	i = DATA_PADDING;
	shape = get_shape(arr);
	r = arr[i].i32x2;
	while (i <= de_uint_x(shape) * de_uint_y(shape))
	{
		tmp = de_int_x(arr[i].i32x2);
		if (tmp < de_int_x(r))
		{
			r = en_i32x2(tmp, de_int_y(r));
		}
		if (de_int_y(r) < tmp)
		{
			r = en_i32x2(de_int_x(r), tmp);
		}
		i += 1;
	}
	return (r);
}

/// return t_i32x2(w, e);
t_i32x2	get_ns(vec2d_64 arr)
{
	t_u32x2		shape;
	t_i32x2		r;
	uint32_t	i;
	int32_t		tmp;

	i = DATA_PADDING;
	shape = get_shape(arr);
	r = arr[i].i32x2;
	while (i <= de_uint_x(shape) * de_uint_y(shape))
	{
		tmp = de_int_y(arr[i].i32x2);
		if (tmp < de_int_x(r))
		{
			r = en_i32x2(tmp, de_int_y(r));
		}
		if (de_int_y(r) < tmp)
		{
			r = en_i32x2(de_int_x(r), tmp);
		}
		i += 1;
	}
	return (r);
}
