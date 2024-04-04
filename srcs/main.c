#include "../MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		exception("Invalid amount of args.");
	return (0);
}

void	exception(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}
