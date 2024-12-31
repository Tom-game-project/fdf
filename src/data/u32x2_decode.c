/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32x2_decode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:15 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 18:25:16 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "u32x2.h"

uint32_t	de_uint_x(t_u32x2 data)
{
	return ((uint32_t)(data >> 32));
}

uint32_t	de_uint_y(t_u32x2 data)
{
	return ((uint32_t)((data << 32) >> 32));
}

