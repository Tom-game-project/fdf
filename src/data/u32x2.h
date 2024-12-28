/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u32x2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:27:42 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:27:43 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U32X2_H
#define U32X2_H

#include <stdint.h>
#include <stdint.h>
#include <limits.h>


/// # t_u32x2
/// |-------64bit-------|
/// |--32bit--|--32bit--|
/// |  uint x |  uint y |
typedef uint64_t t_u32x2;

t_u32x2 en_u32x2(uint32_t x, uint32_t y);
uint32_t de_uint_x(t_u32x2 data);
uint32_t de_uint_y(t_u32x2 data);

// 演算
t_u32x2 t_u32x2_add(t_u32x2 a, t_u32x2 b);
t_u32x2 t_u32x2_sub(t_u32x2 a, t_u32x2 b);
t_u32x2 t_u32x2_mul(t_u32x2 a, t_u32x2 b);


#endif
