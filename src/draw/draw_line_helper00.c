/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:56 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:33:38 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

int	abs(int a)
{
	return (a * (((0 < a) << 1) - 1));
}

bool	int16_gt(uint16_t a, uint16_t b)
{
	return (a > b);
}

uint16_t	int16mf(uint16_t a, uint16_t b)
{
	if (a < b)
	{
		return (b - a);
	}
	else
	{
		return (a - b);
	}
}

uint16_t	shift8_func(uint16_t a, uint16_t b)
{
	(void) b;
	return (a);
}
