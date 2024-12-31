#ifndef FDF_H
#define FDF_H
#include "data/vec2d_64.h"
#include "data/i32x2.h"
#include <stdint.h>

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
	t_i32x2 x_vector;
	t_i32x2 y_vector;
	t_i32x2 z_vector;
	int32_t zoom;
	int bpp;
	int endian;
	int size_l;
};

#endif
