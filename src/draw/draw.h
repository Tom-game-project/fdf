#ifndef DRAW_H
# define DRAW_H

#include "../../minilibx-linux/mlx.h"
#include "../data/vec2d_64.h"
#include "../data/i32x2.h"
#include "../data/u32x2.h"
#include "../data/u16x4.h"

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

typedef struct s_line t_line;
struct s_line
{
	t_i32x2 start;
	t_i32x2 end;
};

typedef struct s_colordiff t_colordiff;
struct s_colordiff
{
	t_u16x4 start;
	t_u16x4 end;
};

vec2d_64 calc_map(vec2d_64 map);
void draw_line(void *mlx_ptr, void *mlx_win, t_line line, t_colordiff color_pair);

#endif
