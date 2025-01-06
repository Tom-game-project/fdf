/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:39:35 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 19:39:36 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "../../minilibx-linux/mlx.h"
# include "../data/i32x2.h"
# include "../draw/draw.h"
# include "../fdf.h"

int		cross_hook(t_mlx_data *data);
t_i32x2	div100(t_i32x2 a, t_mlx_data data);
int		key_event_proc(int key, t_mlx_data *data);
int		loop_hook(t_mlx_data *data);

#endif
