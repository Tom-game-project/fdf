/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:37 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/31 19:59:11 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

// typedef enum e_result t_result;

enum e_result
{
	e_result_ok = 0,
	e_result_allocation_err = 1,
	e_result_load_err = 2,
	e_result_index_out_of_range_err = 3,
	e_result_io_err = 4,
	e_result_arg_err = 5,
};

int	print_error_msg(enum e_result err_code);

#endif
