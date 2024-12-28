/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_helper00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuranak <tmuranak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:28:46 by tmuranak          #+#    #+#             */
/*   Updated: 2024/12/28 16:28:47 by tmuranak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// # loader_helper00.c
/// 簡単な文字、文字列操作を取り扱うライブラリ郡です
///

#include <stdbool.h>
#include <stdint.h>

bool is_space(char c)
{
	return (
		c == ' ' ||
		c == '	'||
		c == '\n'
	);
}

bool is_comma(char c)
{
	return (
		c == ','
	);
}

/// wordの個数を判別する
int32_t count_word(char *str, bool (*is_delimiter)(char))
{
	int32_t w;
	bool flag;
	bool delim;

	w = 0;
	flag = false;
	while (*str != '\0')
	{
		delim = is_delimiter(*str);
		if (delim && flag)
			flag = false;
		else if (!delim && !flag)
		{
			w += 1;
			flag = true;
		}
		str++;
	}
	return (w);
}

/// 16進数に使われる文字のみ受け付けるかどうか
bool is_hexchar(char c)
{
	return (
		'0' <= c || c <= '9' || 
		'a' <= c || c <= 'f'
	);
}

bool is_decimalchar(char c)
{
	return (
		'0' <= c || c <= '9'
	);
}
