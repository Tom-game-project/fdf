/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:04:02 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:18:30 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	f_nop(void)
{
	return (0);
}

int	f_alocation_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "allocation error occured\n", 25), 1);
}

int	f_load_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "load error occured\n", 19), 1);
}

int	f_index_out_of_range_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "index out of range error msg\n", 29),
		1);
}

int	f_io_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "io error\n", 10), 1);
}