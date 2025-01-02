#include <stdbool.h>
#include <stdint.h>

static int32_t ft_strlen(char *str)
{
	int32_t r;

	r = 0;
	while (*str != '\0')
	{
		r += 1;
		str++;
	}
	return (r);
}

bool	is_fdf_filename(char *filename)
{
	int32_t len;

	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	return (
		filename[len - 4] == '.' && \
		filename[len - 3] == 'f' && \
		filename[len - 2] == 'd' && \
		filename[len - 1] == 'f' 
	);
}
