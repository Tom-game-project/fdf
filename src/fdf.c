#include <X11/X.h>
#include <X11/keysym.h>
#include <stdint.h>
#include <stdlib.h>

#include "../minilibx-linux/mlx.h"
#include "data/vec2d_64.h"
#include "draw/draw.h"
#include "fdf_loader/loader.h"

#include "args/args_structs.h"

// test modules 
#include <stdio.h>
#include <unistd.h>

int event_handler(int key, t_mlx_ptr_win *mlx_ptr_win)
{
	printf("called %d \n", key);
	if (key == 113) // if q_key pressed
	{
		mlx_destroy_window(mlx_ptr_win->mlx_ptr, mlx_ptr_win->mlx_win);
		mlx_loop_end(mlx_ptr_win->mlx_ptr);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	void *mlx_ptr;
	void *mlx_win; // canvas的な
	vec2d_64 a;
	vec2d_64 map;

	if (argc == 2)
	{
		mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 1200, 1200, argv[1]);
		mlx_clear_window(mlx_ptr, mlx_win);
		alocate_memory_for_map(&map, argv[1]);
		a = calc_map(map);
		put_lines((t_mlx_ptr_win){mlx_ptr, mlx_win},a, map);
		free(a);
		free(map);
		mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, &(t_mlx_ptr_win) {mlx_ptr, mlx_win });
		mlx_loop(mlx_ptr);
		return (mlx_destroy_display(mlx_ptr), free(mlx_ptr), 0);
	}
	return (1);
}

