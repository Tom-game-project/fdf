/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:57 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 18:19:30 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_H
# define LOADER_H

# include "../data/i32u32.h"
# include "../data/i32x2.h"
# include "../data/vec2d_64.h"
# include "../error/result.h"
# include <stdbool.h>
# include <stdint.h>

// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
# define Z_COLOR_WORD_MAX_LENGTH 23
typedef char	t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

// enum e_result load_map(char *filename);
enum e_result	alocate_memory_for_map(t_vec2d_64 *arr, char *filename);

#endif
