/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:26:18 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 19:43:44 by tmuranak         ###   ########.fr       */
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
#include "../minilibx-linux/mlx.h"
#include "data/i32x2.h"
#include "data/vec2d_64.h"
#include "draw/draw.h"
#include "error/result.h"
#include "fdf.h"
#include "fdf_loader/loader.h"
#include "hook/hook.h"

enum e_result	set_mlx(t_mlx_data *data, char *filename)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (e_result_mlx_err);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			filename);
	if (data->mlx_ptr == NULL)
		return (e_result_mlx_err);
	data->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->mlx_img == NULL)
		return (e_result_mlx_err);
	data->mlx_addr = mlx_get_data_addr(data->mlx_img, &data->bpp, &data->size_l,
			&data->endian);
	if (data->mlx_addr == NULL)
		return (e_result_mlx_err);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	return (e_result_ok);
}

int	set_hooks(t_mlx_data *data)
{
	mlx_hook(data->mlx_win, DestroyNotify, NoEventMask, cross_hook, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_event_proc, data);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	data;

	if (argc == 2)
	{
		if (print_error_msg(alocate_memory_for_map(&data.map, argv[1])))
			return (1);
		if (set_mlx(&data, argv[1]))
			return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), 0);
		data.x_vector = en_i32x2(1732, 1000);
		data.y_vector = en_i32x2(-1732, 1000);
		data.z_vector = en_i32x2(0, -2000);
		data.point_map = calc_map(data.map, (t_vector_directions){data.x_vector,
				data.y_vector, data.z_vector});
		data.zoom = 1000;
		data.position = en_i32x2(0 - de_int_x(get_we(data.point_map)), 0
				- de_int_x(get_ns(data.point_map)));
		put_lines(data, data.point_map, data.map, div100);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 0);
		set_hooks(&data);
		mlx_loop(data.mlx_ptr);
		return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr),
			free(data.map), free(data.point_map), 0);
	}
	return (1);
}
