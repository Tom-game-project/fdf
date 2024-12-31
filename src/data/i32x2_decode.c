/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32x2_decode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:23:33 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:16:05 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "i32x2.h"

int32_t	de_int_x(t_i32x2 data)
{
	return ((int32_t)(data >> 32));
}

int32_t	de_int_y(t_i32x2 data)
{
	return ((int32_t)(data & 0xFFFFFFFF));
}
