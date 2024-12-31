// X11
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

// 
#include <stdint.h>
#include "data/print_data.h"
#include <stdlib.h>
#include <math.h>

#include "../minilibx-linux/mlx.h"
#include "data/i32x2.h"
#include "data/vec2d_64.h"
#include "draw/draw.h"
#include "fdf_loader/loader.h"

#include "fdf.h"


// test modules 
#include <unistd.h>
#include <stdio.h>

static int	cross_hook(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	mlx_loop_end(data->mlx_ptr);
	exit((
			mlx_destroy_display( data->mlx_ptr),
			free(data->mlx_ptr),
			free(data->map),
			free(data->point_map),
			0
		)
	);
	return (0);
}

static t_i32x2 div100(t_i32x2 a, t_mlx_data data)
{
	t_i32x2 r;
	
	r = t_i32x2_add(a, data.position);
	return (en_i32x2(de_int_x(r) / data.zoom, de_int_y(r) / data.zoom));
}

int event_handler(int key, t_mlx_data *data)
{
	if (key == XK_Escape) // if q_key pressed
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	else if (key == XK_w)
	{
		put_back_lines(*data, data->point_map, div100);
		data->position = t_i32x2_add(data->position,en_i32x2(0, -10000));
		put_lines(*data, data->point_map, data->map,div100);
	}
	else if (key == XK_d)
	{
		put_back_lines(*data, data->point_map, div100);
		data->position = t_i32x2_add(data->position,en_i32x2(10000, 0));
		put_lines(*data, data->point_map, data->map,div100);
	}
	else if (key == XK_a)// 
	{
		put_back_lines(*data, data->point_map, div100);
		data->position = t_i32x2_add(data->position,en_i32x2(-10000, 0));
		put_lines(*data, data->point_map, data->map, div100);
	}
	else if (key == XK_s)//(key == XK_Down)
	{
		put_back_lines(*data, data->point_map, div100);
		data->position = t_i32x2_add(data->position,en_i32x2(0, 10000));
		put_lines(*data, data->point_map, data->map, div100);
	}
	else if (key == XK_Up)
	{
	}
	else if (key == XK_Right)
	{
		put_back_lines(*data, data->point_map, div100);
		data->x_vector = t_i32x2_complex_mul(data->x_vector, en_i32x2(866, 500));
		data->x_vector = t_i32x2_div(data->x_vector, en_i32x2(1000, 1000));
		data->y_vector = t_i32x2_complex_mul(data->y_vector, en_i32x2(866, 500));
		data->y_vector = t_i32x2_div(data->y_vector, en_i32x2(1000, 1000));
		set_map(data->point_map, data->map, (t_vector_directions){
			data->x_vector,
			data->y_vector,
			data->z_vector
		});
		//data->z_vector = t_i32x2_complex_mul(data->z_vector, en_i32x2(866, 500));
		//data->z_vector = t_i32x2_div(data->z_vector, en_i32x2(1000, 1000));
		set_map(data->point_map, data->map, (t_vector_directions){
			data->x_vector,
			data->y_vector,
			data->z_vector
		});
		put_lines(*data, data->point_map, data->map, div100);
	}
	else if (key == XK_Left)
	{
		put_back_lines(*data, data->point_map, div100);
		data->x_vector = t_i32x2_complex_mul(data->x_vector, en_i32x2(866, -500));
		data->x_vector = t_i32x2_div(data->x_vector, en_i32x2(1000, 1000));
		data->y_vector = t_i32x2_complex_mul(data->y_vector, en_i32x2(866, -500));
		data->y_vector = t_i32x2_div(data->y_vector, en_i32x2(1000, 1000));
		// data->z_vector = t_i32x2_complex_mul(data->z_vector, en_i32x2(866, -500));
		// data->z_vector = t_i32x2_div(data->z_vector, en_i32x2(1000, 1000));
		set_map(data->point_map, data->map, (t_vector_directions){
			data->x_vector,
			data->y_vector,
			data->z_vector
		});
		set_map(data->point_map, data->map, (t_vector_directions){
			data->x_vector,
			data->y_vector,
			data->z_vector
		});
		put_lines(*data, data->point_map, data->map, div100);
	}
	else if (key == XK_Down)
	{
	}
	else if (key == XK_n){
		put_back_lines(*data, data->point_map, div100);
		data->zoom += 10;
		put_lines(*data, data->point_map, data->map, div100);
	}
	else if (key == XK_m)
	{
		put_back_lines(*data, data->point_map, div100);
		data->zoom -= 10;
		if (data->zoom <= 0)
			data->zoom += 10;
		put_lines(*data, data->point_map, data->map, div100);
	}
	return (0);
}

int loop_hook(t_mlx_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
	return (0);
}

int main(int argc, char *argv[])
{
	t_mlx_data data;

	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
		data.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH,  WINDOW_HEIGHT);
		data.mlx_addr = mlx_get_data_addr(data.mlx_img, &data.bpp, &data.size_l, &data.endian);
		mlx_clear_window(data.mlx_ptr, data.mlx_win);
		alocate_memory_for_map(&data.map, argv[1]);

		data.x_vector = en_i32x2(1732, 1000);
		data.y_vector = en_i32x2(-1732, 1000);
		data.z_vector = en_i32x2(0, -2000);
		data.point_map = calc_map(data.map, (t_vector_directions) {
				data.x_vector,
				data.y_vector,
				data.z_vector
			}
		);
		data.zoom = 1000;
		data.position = en_i32x2(0 - de_int_x(get_we(data.point_map)), 0 - de_int_x(get_ns(data.point_map)));
		put_lines(data,
		data.point_map, data.map, div100);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 0);
		// hook
		mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, cross_hook, &data);
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, event_handler, &data);
		mlx_loop_hook(data.mlx_ptr, loop_hook, &data);
		mlx_loop(data.mlx_ptr);
		return (
				mlx_destroy_display(data.mlx_ptr), 
				free(data.mlx_ptr),
				free(data.map),
				free(data.point_map),
				0
		);
	}
	return (1);
}
