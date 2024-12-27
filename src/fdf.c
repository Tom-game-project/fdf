#include <X11/X.h>
#include <X11/keysym.h>
#include <stdint.h>
#include <stdlib.h>

#include "../minilibx-linux/mlx.h"
#include "data/i32u32.h"
#include "data/i32x2.h"
#include "data/print_data.h"
#include "data/u16x4.h"
#include "data/u32x2.h"
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

int put_line(void *mlx_ptr, void *win_ptr, vec2d_64 arr, vec2d_64 zcolor)
{
	uint32_t y;
	uint32_t x;

	y = 0;
	while (y < de_uint_y(get_shape(zcolor)) - 1)
	{
		x = 0;
		while (x < de_uint_x(get_shape(zcolor)) - 1)
		{
			draw_line
			(
				mlx_ptr, win_ptr,
				(t_line) {
					t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2, en_i32x2(300, 300)),
					t_i32x2_add(get_vec2d_elem(arr, x + 1, y).i32x2, en_i32x2(300, 300))
				},
				(t_colordiff) {	
					conv_u8x4_to_u16x4(
							de_iu_y(get_vec2d_elem(zcolor, x, y).i32u32)),
					conv_u8x4_to_u16x4(
							de_iu_y(get_vec2d_elem(zcolor, x + 1, y).i32u32))
				}
			);
			draw_line
			(
				mlx_ptr, win_ptr,
				(t_line) {
					t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2, en_i32x2(300, 300)),
					t_i32x2_add(get_vec2d_elem(arr, x, y + 1).i32x2, en_i32x2(300, 300))
				},
				(t_colordiff) {	
					conv_u8x4_to_u16x4(
							de_iu_y(get_vec2d_elem(zcolor, x, y).i32u32)),
					conv_u8x4_to_u16x4(
							de_iu_y(get_vec2d_elem(zcolor, x, y + 1).i32u32))
				}
			);
			x += 1;
		}
		y += 1;
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
		mlx_ptr = mlx_init(); // 一番最初に必要
		mlx_win = mlx_new_window(mlx_ptr, 1200, 1200, argv[1]);
		mlx_clear_window(mlx_ptr, mlx_win);
		// 描画に必要な処理
		alocate_memory_for_map(&map, argv[1]);
		a = calc_map(map);
		put_line(mlx_ptr, mlx_win, a, map);
		free(a);
		free(map);
		mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, &(t_mlx_ptr_win) {
				mlx_ptr,
				mlx_win
		});
		mlx_loop(mlx_ptr);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	} else
		return (1);
}

