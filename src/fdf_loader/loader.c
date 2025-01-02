/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:49:01 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 18:15:27 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/i32x2.h"
#include "loader.h"
#include "loader_helper.h"
#include <stdlib.h>

/// 配列用のデータを格納するための領域を確保してメモリに読み込んだデータをセットする
enum e_result	alocate_memory_for_map(t_vec2d_64 *arr, char *filename)
{
	t_u32x2			mapsize;
	enum e_result	err;

	if (!is_fdf_filename(filename))
		return (e_result_is_not_fdf_file_err);
	mapsize = get_mapsize(filename, &err);
	if (err == e_result_io_err)
		return (e_result_io_err);
	else if (err == e_result_load_err)
		return (e_result_load_err);
	if (mapsize == en_u32x2(0, 0))
		return (e_result_load_err);
	if (de_int_x(mapsize) == -1)
		return (e_result_load_err);
	*arr = init_t_vec2d_64(de_uint_x(mapsize), de_uint_y(mapsize));
	if (*arr == NULL)
		return (e_result_allocation_err);
	return (load_map(*arr, filename));
}
