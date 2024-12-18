#ifndef DRAW_H
# define DRAW_H

#include "../../minilibx-linux/mlx.h"

typedef struct s_position t_position;

struct s_position{
	int x;
	int y;
};

void draw_line(void *mlx_ptr, void *mlx_win, int x0, int y0, int x1, int y1);

#endif
