/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:02 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:41:53 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_line_helper.h"

void	draw_line(t_mlx_ptr_win mlx_ptr_win, t_line l, t_colorpair cp)
{
	draw_line_helper(mlx_ptr_win, l, (t_colordiff){conv_u8x4_to_u16x4(cp.s),
		conv_u8x4_to_u16x4(cp.e)});
}

void	draw_back_line(t_mlx_ptr_win mlx_ptr_win, t_line l)
{
	draw_back_line_helper(mlx_ptr_win, l);
}
