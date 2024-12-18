#include <X11/X.h>
#include <X11/keysym.h>
#include <stdint.h>
#include "../minilibx-linux/mlx.h"
#include "draw/draw.h"
#include "data/u32x2.h"

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
	// t_u32x2 zc;
	// uint32_t z = (uint32_t) 123;
	// uint32_t color = (uint32_t) 321;
	// zc = encode_u32x2(z, color);
	// printf("x %d\n", decode_x(zc));
	// printf("y %d\n", decode_y(zc));
	// printf("x %d\n", decode_x(zc));
	// printf("y %d\n", decode_y(zc));

	vec2d_u32x2 a = init_vec2d_u32x2(3, 3);
	for (uint32_t y = 0; y < 3;y++)
	{
		for (uint32_t x = 0; x < 3;x++)
		{
			set_vec2d_u32x2_elem(a, x, y, encode_u32x2(x, y));
		}
	}
	t_u32x2 tmp;
	for (uint32_t y = 0; y < 3;y++)
	{
		for (uint32_t x = 0; x < 3;x++)
		{
			tmp = get_vec2d_u32x2_elem(a, x, y);
			printf("%d %d\n", decode_x(tmp), decode_y(tmp));
		}
	}
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

