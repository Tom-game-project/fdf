/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:59 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:46:24 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_HELPER_H
# define DRAW_LINE_HELPER_H

# include <stdint.h>
# include <stdbool.h>
# include "draw.h"

int		abs(int a);
bool	int16_lt(int16_t a, int16_t b);
int16_t	int16mf(int16_t a, int16_t b);
int16_t	shift8_func(int16_t a, int16_t b);

void	draw_line_helper(t_mlx_ptr_win mlx_ptr_win, t_line l, \
		t_colordiff cp);
void	draw_back_line_helper(t_mlx_ptr_win mlx_ptr_win, t_line l);

#endif
