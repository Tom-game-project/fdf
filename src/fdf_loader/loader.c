#include "gnl/get_next_line.h"
#include "../error/result.h"

#include <fcntl.h>

#include <stdbool.h>
#include <stdint.h>

// for test
#include <stdio.h>

// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
#define Z_COLOR_WORD_MAX_LENGTH 23
typedef char t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

bool is_space(char c)
{
	return (
			c == ' ' ||\
			c == '	'||\
			c == '\n'
	);
}

/// wordの個数を判別する
uint32_t count_word(char *str, bool (*is_delimiter)(char))
{
	uint32_t w;
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

/// 返り値はエラーコード
enum e_result get_z_color_word(\
	char *str,\
	t_z_color_word word,\
	uint32_t index,\
	bool (*is_delimiter)(char)
)
{
	int32_t i;
	uint32_t w;
	bool flag;

	i = 0;
	w = 0;
	flag = false;
	while (*str != '\0')
	{
		if (is_delimiter(*str) && flag)
		{
			flag = false;
			w += 1;
		}
		else if (!is_delimiter(*str) && !flag)
			flag = true;
		if (flag && w == index && i < Z_COLOR_WORD_MAX_LENGTH - 1) // null文字ぶん引く
			word[i++] = *str;
		str++;
	}
	if (Z_COLOR_WORD_MAX_LENGTH < i)
		return (e_result_load_err);
	word[i] = '\0'; // 最大の場合iは23
	return (e_result_ok);
}



enum e_result load_map(char *filename)
{
	int fd;
	char	*buf;
	int counter;
	t_z_color_word zcw;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("error 1");
		return (e_result_io_err);
	}
	counter = 0;
	while (true)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		printf("count_word -> %d %d: %s", count_word(buf, is_space) , counter, buf);
		get_z_color_word(buf, zcw, 2, is_space);
		printf("index 2 \"%s\"\n", zcw);
		free(buf);
		counter++;
	}
	close(fd);
	return (0);
}

