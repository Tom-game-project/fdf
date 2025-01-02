#ifndef HOOK_HELPER_H
#define HOOK_HELPER_H

#include <stdint.h>
#include "../data/i32x2.h"
#include "../fdf.h"

int lateral_movement(t_mlx_data *data, int32_t x, int32_t y);
int zoom_movement(t_mlx_data *data, int32_t zoom);
int rotate_movement(t_mlx_data *data, t_i32x2 complex_num);

#endif
