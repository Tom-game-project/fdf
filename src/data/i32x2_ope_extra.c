/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32x2_ope_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:23:44 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 13:43:07 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "i32x2.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

int32_t	t_i32x2_dot(t_i32x2 a, t_i32x2 b)
{
	return (de_int_x(a) * de_int_x(b) + de_int_y(a) * de_int_y(b));
}

int32_t	t_i32x2_max(t_i32x2 a)
{
	if (de_int_x(a) < de_int_y(a))
		return (de_int_y(a));
	else
		return (de_int_x(a));
}

bool	t_i32x2_eq(t_i32x2 a, t_i32x2 b)
{
	return (de_int_x(a) == de_int_x(b) && de_int_y(a) == de_int_y(b));
}
