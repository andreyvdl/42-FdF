#include "../include/fdf.h"

static bool	file_name_is_wrong(char *file)
{
	char	*dot_pos;

	dot_pos = ft_strrchr(file, '.');
	if (dot_pos != NIL)
		if (ft_strcmp(dot_pos, ".fdf"))
			return (false);
	return (true);
}

bool	file_is_invalid(char *file)
{
	int	fd;

	if (file_name_is_wrong(file))
		return (true);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(PERR_FILE);
		return (true);
	}
	close(fd);
	return (false);
}
