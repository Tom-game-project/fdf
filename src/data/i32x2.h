/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i32x2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:08 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:34:55 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I32X2_H
# define I32X2_H

# include <stdint.h>
# include <stdbool.h>

// # t_i32x2
/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |  int x  |  int y  |
typedef uint64_t	t_i32x2;

/// encode 
t_i32x2	en_i32x2(int32_t x, int32_t y);

/// decode
int32_t	de_int_x(t_i32x2 data);
int32_t	de_int_y(t_i32x2 data);

// 演算
t_i32x2	t_i32x2_add(t_i32x2 a, t_i32x2 b);
t_i32x2	t_i32x2_sub(t_i32x2 a, t_i32x2 b);
t_i32x2	t_i32x2_mul(t_i32x2 a, t_i32x2 b);
t_i32x2 t_i32x2_div(t_i32x2 a,t_i32x2 b);
int32_t	t_i32x2_dot(t_i32x2 a, t_i32x2 b);
t_i32x2	t_i32x2_scalar(int32_t a, t_i32x2 b);
int32_t	t_i32x2_max(t_i32x2 a);
bool	t_i32x2_eq(t_i32x2 a, t_i32x2 b);

// 複素数

t_i32x2 t_i32x2_complex_mul(t_i32x2 a, t_i32x2 b);
#endif
