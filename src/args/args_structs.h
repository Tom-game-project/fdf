#ifndef ARGS_STRUCTS_H
#define ARGS_STRUCTS_H

#include "../data/i32x2.h"
#include "../data/u32x2.h"
#include "../data/u16x4.h"

typedef struct s_mlx_ptr_win t_mlx_ptr_win;
struct s_mlx_ptr_win
{
	void *mlx_ptr;
	void *mlx_win;
};

typedef struct s_line t_line;
struct s_line
{
	t_i32x2 s; // start
	t_i32x2 e; // end
};


typedef struct s_colordiff t_colordiff;
struct s_colordiff
{
	t_u16x4 s; // start
	t_u16x4 e; // end
};

#endif
