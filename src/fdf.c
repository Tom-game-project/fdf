#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include <stdint.h>
#include <stdio.h>
#include "data/print_data.h"
#include <stdlib.h>

#include "../minilibx-linux/mlx.h"
#include "data/i32x2.h"
#include "data/vec2d_64.h"
#include "draw/draw.h"
#include "fdf_loader/loader.h"

#include "args/args_structs.h"

// test modules 
#include <unistd.h>

typedef struct s_mlx_data	t_mlx_data;
struct s_mlx_data
{
	void *mlx_ptr;
	void *mlx_win;
	void *mlx_img;
	void *mlx_addr;
	vec2d_64 map;
	vec2d_64 point_map;
	t_i32x2 position;
	int bpp;
	int endian;
	int size_l;
};

typedef struct s_state		t_state;
struct s_state
{
	t_i32x2 p;
};

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

int event_handler(int key, t_mlx_data *data)
{
	if (key == XK_Escape) // if q_key pressed
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
		mlx_loop_end(data->mlx_ptr);
	}
	if (key == XK_Up){
	add_vec_i32x2(data->point_map, data->position);
	put_back_lines((t_mlx_ptr_win){data->mlx_ptr,data->mlx_win, data->mlx_img, data->mlx_addr}, data->point_map);
	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
		data->position = t_i32x2_add(data->position, en_i32x2(0, -10));
		add_vec_i32x2(data->point_map, data->position);
	put_lines((t_mlx_ptr_win){ 
			data->mlx_ptr,
			data->mlx_win,
			data->mlx_img,
			data->mlx_addr 
	}, data->point_map, data->map);

	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
	}
	else if (key == XK_Right){
	add_vec_i32x2(data->point_map, data->position);
	put_back_lines((t_mlx_ptr_win){data->mlx_ptr,data->mlx_win, data->mlx_img, data->mlx_addr}, data->point_map);
	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
		data->position = t_i32x2_add(data->position, en_i32x2(10, 0));
		add_vec_i32x2(data->point_map, data->position);
	put_lines((t_mlx_ptr_win){ 
			data->mlx_ptr,
			data->mlx_win,
			data->mlx_img,
			data->mlx_addr 
	}, data->point_map, data->map);

	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
	}
	else if (key == XK_Left){
	add_vec_i32x2(data->point_map, data->position);
	put_back_lines((t_mlx_ptr_win){data->mlx_ptr,data->mlx_win, data->mlx_img, data->mlx_addr}, data->point_map);
	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
		data->position = t_i32x2_add(data->position, en_i32x2(-10, 0));
		add_vec_i32x2(data->point_map, data->position);
	put_lines((t_mlx_ptr_win){ 
			data->mlx_ptr,
			data->mlx_win,
			data->mlx_img,
			data->mlx_addr 
	}, data->point_map, data->map);

	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
	}
	else if (key == XK_Down){
	add_vec_i32x2(data->point_map, data->position);
	put_back_lines((t_mlx_ptr_win){data->mlx_ptr,data->mlx_win, data->mlx_img, data->mlx_addr}, data->point_map);
	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
		data->position = t_i32x2_add(data->position, en_i32x2(0, 10));
		add_vec_i32x2(data->point_map, data->position);
	put_lines((t_mlx_ptr_win){ 
			data->mlx_ptr,
			data->mlx_win,
			data->mlx_img,
			data->mlx_addr 
	}, data->point_map, data->map);

	add_vec_i32x2(data->point_map, t_i32x2_scalar(-1, data->position));
	}
	// print_i32x2(data->position);
	return (0);
}

/*
int event_handler2(int key, t_mlx_data *data)
{
	return (0);
}
*/

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
		data.point_map = calc_map(data.map, (t_vector_directions) {
				en_i32x2(17, 10),
				en_i32x2(-17, 10),
				en_i32x2(0, -20),
			}
		);
		data.position = en_i32x2(300, 300);
		add_vec_i32x2(data.point_map, data.position);
		put_lines((t_mlx_ptr_win){ 
				data.mlx_ptr,
			       	data.mlx_win,
			       	data.mlx_img,
			       	data.mlx_addr 
		},
		data.point_map, data.map);
		add_vec_i32x2(data.point_map, t_i32x2_scalar(-1, data.position));
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 0);
		// hook
		mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, cross_hook, &data);
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, event_handler, &data);
		mlx_loop_hook(data.mlx_ptr, loop_hook, &data);
		//mlx_hook(data.mlx_win, KeyPress, KeyPressMask, event_handler2, &data);
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
