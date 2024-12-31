/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u16x4_decode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:24:09 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 18:24:52 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "u16x4.h"

uint16_t	de_u16x4_a(t_u16x4 data)
{
	return ((uint16_t)(data >> 48));
}

uint16_t	de_u16x4_b(t_u16x4 data)
{
	return ((uint16_t)((data >> 32) & 0xFFFF));
}

uint16_t	de_u16x4_c(t_u16x4 data)
{
	return ((uint16_t)((data >> 16) & 0xFFFF));
}

uint16_t	de_u16x4_d(t_u16x4 data)
{
	return ((uint16_t)(data & 0xFFFF));
}
