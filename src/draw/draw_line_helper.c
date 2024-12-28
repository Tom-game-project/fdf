/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:56 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 17:28:59 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

int		abs(int a)
{
	return (a * (((0 < a) << 1) - 1));
}

bool	int16_lt(int16_t a, int16_t b)
{
	return (a < b);
}

int16_t	int16mf(int16_t a, int16_t b)
{
	return (abs(a - b));
}

int16_t	shift8_func(int16_t a, int16_t b)
{
	(void) b;
	return (a << 8);
}
