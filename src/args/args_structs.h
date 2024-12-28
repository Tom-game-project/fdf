/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:26:36 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:32:54 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_STRUCTS_H
# define ARGS_STRUCTS_H

# include "../data/i32x2.h"
# include "../data/u32x2.h"
# include "../data/u16x4.h"

typedef struct s_mlx_ptr_win	t_mlx_ptr_win;

struct s_mlx_ptr_win
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int	*mlx_addr;
};

typedef struct s_line			t_line;

struct s_line
{
	t_i32x2	s;
	t_i32x2	e;
};

typedef struct s_colorpair		t_colorpair;

struct s_colorpair
{
	t_u8x4	s;
	t_u8x4	e;
};

#endif
