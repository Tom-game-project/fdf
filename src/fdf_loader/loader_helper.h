/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:43 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:58:21 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_HELPER_H
# define LOADER_HELPER_H

# include "../data/i32u32.h"
# include "../data/i32x2.h"
# include "../data/u32x2.h"
# include "../data/vec2d_64.h"
# include <stdbool.h>
# include <stdint.h>

// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
# define Z_COLOR_WORD_MAX_LENGTH 23

typedef char	t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

// 簡単な文字列の操作
bool			is_space(char c);
bool			is_comma(char c);
int32_t			count_word(char *str, bool (*is_delimiter)(char));
bool			is_hexchar(char c);
bool			is_decimalchar(char c);

// 文字列から数字への変換
uint32_t		get_hex_index(char c);
t_u32x2			colorcode2uint32(char *str);
int32_t			str2int(char *str);
bool			is_fdf_filename(char *filename);

enum e_result	get_z_color_word(char *str, t_z_color_word word, uint32_t x,
					bool (*is_delimiter)(char));

t_i32x2			get_mapsize(char *filename, enum e_result *err);
t_i32u32		z_color2t_i32u32(t_z_color_word zcolor, int *err);
enum e_result	set_row(uint32_t y, t_u32x2 mapsize, char *buf, vec2d_64 arr);
enum e_result	load_map(vec2d_64 arr, char *filename);

#endif
