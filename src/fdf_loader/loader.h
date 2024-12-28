/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:57 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:28:58 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_H
#define LOADER_H

#include <stdint.h>
#include <stdbool.h>
#include "../error/result.h"
#include "../data/i32x2.h"
#include "../data/i32u32.h"
#include "../data/vec2d_64.h"

// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
#define Z_COLOR_WORD_MAX_LENGTH 23
typedef char t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

uint32_t count_word(char *str, bool (*is_delimiter)(char));
//enum e_result load_map(char *filename);
t_i32x2 get_mapsize(char *filename);
t_u32x2 colorcode2uint32(char *str);
t_i32u32 z_color2t_i32u32(t_z_color_word zcolor);
int set_row(uint32_t y, t_i32x2 mapsize, char *buf, vec2d_64 arr);

enum e_result alocate_memory_for_map(vec2d_64 *arr, char *filename);
#endif

