#include "gnl/get_next_line.h"
#include <fcntl.h>

#include <stdbool.h>
#include <stdint.h>

// for test
#include <stdio.h>


bool is_space(char c)
{
	return (
			c == ' ' ||\
			c == '	'
	);
}

/// wordの個数を判別する
uint32_t count_word(char *str, bool (*is_delimiter)(char))
{
	uint32_t i;
	uint32_t w;
	bool flag;

	i = 0;
	w = 0;
	flag = false;
	while (str[i] != '\0')
	{
		if (is_delimiter(str[i]))
		{
			if (flag)
				flag = false;
		}
		else
		{
			if (!flag)
			{
				w += 1;
				flag = true;
			}
		}
		i += 1;
	}
	return (w);
}


///
int load_map(char *filename)
{
	int fd;
	char	*buf;
	int counter;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("error 1");
		return (1);
	}
	buf = get_next_line(fd);
	printf("0 %s", buf);
	counter = 1;
	while (buf)
	{
		buf = get_next_line(fd);
		printf("%d %s", counter, buf);
		if (!buf)
			free(buf);
		//free(buf);
        counter++;
	}
	close(fd);
	return (0);
}

