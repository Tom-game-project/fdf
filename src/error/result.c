/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:56 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:12:43 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "error_msg_helper.h"

#define ERROR_VALIATION 10

int	set_error_msg_function(int (*func[ERROR_VALIATION])())
{
	func[e_result_ok] = f_nop;
	func[e_result_allocation_err] = f_alocation_error_msg;
	func[e_result_load_err] = f_load_error_msg;
	func[e_result_io_err] = f_io_error_msg;
	func[e_result_arg_err] = f_arg_error_msg;
	func[e_result_is_not_fdf_file_err] = f_is_not_fdf_file_msg;
	func[e_result_mlx_err] = f_mlx_error_msg;
	return (0);
}

int	print_error_msg(enum e_result err_code)
{
	int	(*func[ERROR_VALIATION])();

	set_error_msg_function(func);
	return (func[err_code]());
}
