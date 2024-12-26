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

// test modules 
#include <stdio.h>
#include <unistd.h>

// color #0x00RRGGBB
// color definition
#define RED    0x00FF0000
#define GREEN  0x0000FF00
#define BLUE   0x000000FF

int event_handler(int key, void *mlx)
{
	(void) mlx;
	printf("called %d \n", key);
	return (0);
}

int put_vec2d_elem_i32x2(void *mlx_ptr, void *win_ptr, vec2d_64 arr)
{
	t_64_elem tmp;
	uint32_t y;
	uint32_t x;

	y = 0;
	while (y < decode_uint_y(get_shape(arr)))
	{
		x = 0;
		while (x < decode_uint_x(get_shape(arr)))
		{
			tmp.i32x2 = get_vec2d_elem(arr, x, y).i32x2;
			mlx_pixel_put(
				mlx_ptr,
				win_ptr, 
				decode_int_x(tmp.i32x2) + 200,
			       	decode_int_y(tmp.i32x2) + 200,
			       	RED
				);
			x += 1;
		}
		y += 1;
	}
	return (0);
}



int put_line2(void *mlx_ptr, void *win_ptr, vec2d_64 arr, vec2d_64 zcolor)
{	
	uint32_t y;
	uint32_t x;

	(void) zcolor;
	y = 0;
	while (y < decode_uint_y(get_shape(zcolor)) - 1)
	{
		x = 0;
		while (x < decode_uint_x(get_shape(zcolor)) - 1)
		{

			draw_line
			(
					mlx_ptr,
					win_ptr,
					decode_int_x(t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2,encode_i32x2(200,200))),
					decode_int_y(t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2,encode_i32x2(200,200))),
					decode_int_x(t_i32x2_add(get_vec2d_elem(arr, x + 1, y).i32x2,encode_i32x2(200,200))),
					decode_int_y(t_i32x2_add(get_vec2d_elem(arr, x + 1, y).i32x2,encode_i32x2(200,200)))
			);
			draw_line
			(
					mlx_ptr,
					win_ptr,
					decode_int_x(t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2,encode_i32x2(200,200))),
					decode_int_y(t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2,encode_i32x2(200,200))),
					decode_int_x(t_i32x2_add(get_vec2d_elem(arr, x, y + 1).i32x2,encode_i32x2(200,200))),
					decode_int_y(t_i32x2_add(get_vec2d_elem(arr, x, y + 1).i32x2,encode_i32x2(200,200)))
			);
			x += 1;
		}
		y += 1;
	}
	return (0);

}

int put_line(void *mlx_ptr, void *win_ptr, vec2d_64 arr, vec2d_64 zcolor)
{
	uint32_t y;
	uint32_t x;

	y = 0;
	while (y < decode_uint_y(get_shape(zcolor)))
	{
		x = 0;
		while (x < decode_uint_x(get_shape(zcolor)) - 1)
		{
			draw_line2
			(
				(t_mlx_ptr_win) {
					mlx_ptr,
					win_ptr
				},
				(t_line) {
					t_i32x2_add(get_vec2d_elem(arr, x, y).i32x2, encode_i32x2(200, 200)),
					t_i32x2_add(get_vec2d_elem(arr, x + 1, y).i32x2, encode_i32x2(200, 200))
				},
				(t_colordiff) {	
					conv_u8x4_to_u16x4(
							decode_iu_y(get_vec2d_elem(zcolor, x, y).i32u32)),
					conv_u8x4_to_u16x4(
							decode_iu_y(get_vec2d_elem(zcolor, x + 1, y).i32u32))
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
		mlx_win = mlx_new_window(mlx_ptr, 600, 600, argv[1]);
		mlx_clear_window(mlx_ptr, mlx_win);
		// 描画に必要な処理
		alocate_memory_for_map(&map, "maps/test_maps/42.fdf");
		a = calc_map(map);

		put_vec2d_elem_i32x2(mlx_ptr, mlx_win, a);
		put_line2(mlx_ptr, mlx_win, a, map);
		//put_line(mlx_ptr, mlx_win, a, map);
		free(a);
		free(map);
		//draw_line2(
		//	(t_mlx_ptr_win) {
		//		mlx_ptr,
		//		mlx_win
		//	},
		//	(t_line) {
		//		encode_i32x2(200,200),	
		//		encode_i32x2(32,54)
		//	},
		//	(t_colordiff) {
		//		conv_u8x4_to_u16x4(RED),
		//		conv_u8x4_to_u16x4(BLUE)
		//	}
		//);
		draw_line3(
				mlx_ptr,
				mlx_win,

				encode_i32x2(200, 200),
				encode_i32x2(32, 54)
		);
		print_u16x4(
				conv_u8x4_to_u16x4(RED)
		);
		mlx_hook(mlx_win, KeyPress, KeyPressMask, event_handler, mlx_ptr);
		mlx_loop(mlx_ptr);
	}else {
		return (1);
	}
}

