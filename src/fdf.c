#include <X11/X.h>
#include <X11/keysym.h>
#include <stdint.h>
#include "../minilibx-linux/mlx.h"
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

int main(void)
{
	void *mlx_ptr;
	void *mlx_win; // canvas的な

	mlx_ptr = mlx_init(); // 一番最初に必要
	mlx_win = mlx_new_window(mlx_ptr, 300, 300, "Hello World");
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
}

