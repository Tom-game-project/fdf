#include <X11/X.h>
//
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include <stdint.h>
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
	int bpp;
	int endian;
	int size_l;
};

int event_handler(int key, t_mlx_ptr_win *mlx_ptr_win)
{
	if (key == XK_Escape) // if q_key pressed
	{
		mlx_destroy_window(mlx_ptr_win->mlx_ptr, mlx_ptr_win->mlx_win);
		mlx_destroy_image(mlx_ptr_win->mlx_ptr, mlx_ptr_win->mlx_img);
		mlx_loop_end(mlx_ptr_win->mlx_ptr);
	}
	return (0);
}

static int	cross_hook(t_mlx_ptr_win *mlx_ptr_win)
{
	mlx_destroy_window(mlx_ptr_win->mlx_ptr, mlx_ptr_win->mlx_win);
	mlx_destroy_image(mlx_ptr_win->mlx_ptr, mlx_ptr_win->mlx_img);
	mlx_loop_end(mlx_ptr_win->mlx_ptr);
	return (0);
}


int main(int argc, char *argv[])
{
	t_mlx_data data;
	vec2d_64 a;
	vec2d_64 map;

	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
		data.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH,  WINDOW_HEIGHT);
		data.mlx_addr = mlx_get_data_addr(data.mlx_img, &data.bpp, &data.size_l, &data.endian);
		mlx_clear_window(data.mlx_ptr, data.mlx_win);
		alocate_memory_for_map(&map, argv[1]);
		a = calc_map(map);
		add_vec_i32x2(a, en_i32x2(300, 300));
		put_lines((t_mlx_ptr_win){ data.mlx_ptr, 
		data.mlx_win, data.mlx_img, data.mlx_addr },a, map);
		free(a);
		free(map);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.mlx_img, 0, 0);
		// hook
		mlx_hook(data.mlx_win, DestroyNotify, NoEventMask, cross_hook, &(t_mlx_ptr_win) {data.mlx_ptr, data.mlx_win ,data.mlx_img,data.mlx_addr});
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, event_handler, &(t_mlx_ptr_win) {data.mlx_ptr, data.mlx_win ,data.mlx_img,data.mlx_addr});
		mlx_loop(data.mlx_ptr);
		return (mlx_destroy_display(data.mlx_ptr), free(data.mlx_ptr), 0);
	}
	return (1);
}
