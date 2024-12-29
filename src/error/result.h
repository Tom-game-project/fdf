/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:37 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:28:38 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef result_h
#define result_h

// typedef enum e_result t_result;


enum e_result
{
	// ok
	e_result_ok = 0,
	// error
	e_result_allocation_err = 1, // メモリの割当に失敗したときのエラー
	e_result_load_err = 2, // 不正なファイルを読み込んだ際のエラー
	e_result_index_out_of_range_err = 3, //　配列に不正なアクセスをしようとしたとき
	e_result_io_err = 4,
	e_result_arg_err = 5,
};

#endif
