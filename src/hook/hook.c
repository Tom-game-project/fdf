/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:39:30 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 19:39:32 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// X11
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

// std
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

// mlx
#include "../../minilibx-linux/mlx.h"
#include "../data/i32x2.h"
#include "../fdf.h"
#include "hook_helper.h"

int	cross_hook(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_loop_end(data->mlx_ptr);
	exit((mlx_destroy_display(data->mlx_ptr), free(data->mlx_ptr),
			free(data->map), free(data->point_map), 0));
	return (0);
}

t_i32x2	div100(t_i32x2 a, t_mlx_data data)
{
	t_i32x2	r;

	r = t_i32x2_add(a, data.position);
	return (en_i32x2(de_int_x(r) / data.zoom, de_int_y(r) / data.zoom));
}

int	key_event_proc(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
		cross_hook(data);
	else if (key == XK_w)
		lateral_movement(data, 0, -10000);
	else if (key == XK_d)
		lateral_movement(data, 10000, 0);
	else if (key == XK_a)
		lateral_movement(data, -10000, 0);
	else if (key == XK_s)
		lateral_movement(data, 0, 10000);
	else if (key == XK_Right)
		rotate_movement(data, en_i32x2(866, 500));
	else if (key == XK_Left)
		rotate_movement(data, en_i32x2(866, -500));
	else if (key == XK_n)
		zoom_movement(data, 10);
	else if (key == XK_m)
		zoom_movement(data, -10);
	return (0);
}

int	loop_hook(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
	return (0);
}
