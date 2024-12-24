#include <X11/X.h>
#include <X11/keysym.h>
#include <stdint.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"
#include "data/i32x2.h"
#include "draw/draw.h"

// test modules 
#include <stdio.h>

// color #0x00RRGGBB
// color definition
#define RED    0x00FF0000
#define GREEN  0x0000FF00
#define BLUE   0x000000FF

#define X_VEC 2
#define Y_VEC -1
#define Z_VEC 1

int event_handler(int key, void *mlx)
{
	(void) mlx;
	printf("called %d \n", key);
	return (0);
}

int print_vec2d_elem_i32x2(void *mlx_ptr, void *win_ptr, vec2d_64 arr)
{
	t_64_elem tmp;

	for (uint32_t y = 0; y < decode_uint_y(get_shape(arr)); y++)
	{
		for (uint32_t x = 0; x < decode_uint_x(get_shape(arr)); x++)
		{
			tmp.i32x2 = get_vec2d_elem(arr, x, y).i32x2;
			// print_i32x2(tmp.i32x2);
			mlx_pixel_put(mlx_ptr, win_ptr, decode_int_x(tmp.i32x2), decode_int_y(tmp.i32x2), RED);
		}
		printf("\n");
	}
	return (0);
}

int main(int argc, char *argv[])
{
	void *mlx_ptr;
	void *mlx_win; // canvas的な

	if (argc == 2)
	{
		mlx_ptr = mlx_init(); // 一番最初に必要
		mlx_win = mlx_new_window(mlx_ptr, 600, 600, argv[1]);
		mlx_clear_window(mlx_ptr, mlx_win);
		for (int i = 0; i< 10; i++){
			mlx_pixel_put(mlx_ptr, mlx_win, 10, i, RED);
		}
		for (int i = 0; i< 10; i++){
			mlx_pixel_put(mlx_ptr, mlx_win, 10, i, RED);
		}
		mlx_pixel_put(mlx_ptr, mlx_win, 10, 10000, RED);
		draw_line(mlx_ptr, mlx_win, 10,10, 100, 100);
		mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, mlx_ptr);
		mlx_loop(mlx_ptr);
	}else {
		exit(1);
	}
}

