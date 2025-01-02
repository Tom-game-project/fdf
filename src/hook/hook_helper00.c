// X11
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

// std
#include <stdint.h>
#include <unistd.h>

// mlx
#include "../data/i32x2.h"
#include "../draw/draw.h"
#include "../fdf.h"
#include "hook.h"

int lateral_movement(t_mlx_data *data, int32_t x, int32_t y)
{
	put_back_lines(*data, data->point_map, div100);
	data->position = t_i32x2_add(data->position, en_i32x2(x, y));
	put_lines(*data, data->point_map, data->map, div100);
	return (0);
}

int zoom_movement(t_mlx_data *data, int32_t zoom)
{
	put_back_lines(*data, data->point_map, div100);
	data->zoom += zoom;
	if (zoom < 0 && data->zoom <= 0)
		data->zoom -= zoom;
	put_lines(*data, data->point_map, data->map, div100);
	return (0);
}

int rotate_movement(t_mlx_data *data, t_i32x2 complex_num)
{
	put_back_lines(*data, data->point_map, div100);
	data->x_vector = t_i32x2_complex_mul(data->x_vector, complex_num);
	data->x_vector = t_i32x2_div(data->x_vector, en_i32x2(1000, 1000));
	data->y_vector = t_i32x2_complex_mul(data->y_vector, complex_num);
	data->y_vector = t_i32x2_div(data->y_vector, en_i32x2(1000, 1000));
	set_map(data->point_map, data->map,
		(t_vector_directions){data->x_vector, data->y_vector,
		data->z_vector});
	set_map(data->point_map, data->map,
		(t_vector_directions){data->x_vector, data->y_vector,
		data->z_vector});
	put_lines(*data, data->point_map, data->map, div100);
	return (0);
}
