#ifndef DRAW_H
# define DRAW_H

#include "../../minilibx-linux/mlx.h"
#include "../data/vec2d_64.h"

typedef struct s_position t_position;

struct s_position{
	int x;
	int y;
};

typedef struct s_mlx_ptr_win t_mlx_ptr_win;
struct s_mlx_ptr_win
{
	void *mlx_ptr;
	void *mlx_win;
};

void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1);
vec2d_64 calc_map(vec2d_64 map);
void draw_line2(t_mlx_ptr_win data, t_i32x2 p0, t_i32x2 p1);

#endif
