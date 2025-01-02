/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:25:56 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:11:04 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "result.h"
#include "unistd.h"

#define ERROR_VALIATION 10

static int f_nop()
{
	return (0);
}

int f_alocation_error_msg()
{
	return ((void) write(STDERR_FILENO, "allocation error occured\n", 25), 1);
}

int f_load_error_msg()
{
	return ((void) write(STDERR_FILENO, "load error occured\n", 19), 1);
}

int f_index_out_of_range_error_msg()
{
	return ((void) write(STDERR_FILENO, "index out of range error msg\n", 29), 1);
}

int f_io_error_msg()
{
	return ((void) write(STDERR_FILENO, "io error\n", 10), 1);
}

int f_arg_error_msg()
{
	return ((void) write(STDERR_FILENO, "args error\n", 12), 1);
}

int f_is_not_fdf_file_msg()
{
	return ((void) write(STDERR_FILENO, "is not fdf file\n", 16), 1);
}

int set_error_msg_function(
	int (*func[ERROR_VALIATION])()
)
{
	func[e_result_ok] = f_nop;
	func[e_result_allocation_err] = f_alocation_error_msg;
	func[e_result_load_err] = f_load_error_msg;
	func[e_result_io_err] = f_io_error_msg;
	func[e_result_arg_err] = f_arg_error_msg;
	func[e_result_is_not_fdf_file_err] = f_is_not_fdf_file_msg;
	return (0);
}

int print_error_msg(enum e_result err_code)
{
	int (*func[ERROR_VALIATION])();

	set_error_msg_function(func);
	return (func[err_code]());
}
