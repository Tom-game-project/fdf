/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:04:19 by tmuranak          #+#    #+#             */
/*   Updated: 2025/01/02 17:12:09 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	f_arg_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "args error\n", 12), 1);
}

int	f_is_not_fdf_file_msg(void)
{
	return ((void)write(STDERR_FILENO, "is not fdf file\n", 16), 1);
}

int	f_mlx_error_msg(void)
{
	return ((void)write(STDERR_FILENO, "minilibx error\n", 15), 1);
}
