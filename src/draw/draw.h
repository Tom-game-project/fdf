#ifndef DRAW_H
# define DRAW_H

#include "../../minilibx-linux/mlx.h"
#include "../data/vec2d_64.h"
#include "../data/i32x2.h"
#include "../data/u32x2.h"
#include "../data/u16x4.h"
#include "../args/args_structs.h"

typedef struct s_position t_position;

struct s_position{
	int x;
	int y;
};

vec2d_64 calc_map(vec2d_64 map);
void draw_line(void *mlx_ptr, void *mlx_win, t_line line, t_colordiff color_pair);

#endif
