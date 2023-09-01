#include "../include/fdf.h"

// static void	wireframe(char *file)
// {
// 	t_fdf	fdf;


// }

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_argc();
		exit(EXIT_FAILURE);
	}
	if (file_is_invalid(*(argv + 1)))
	{
		ft_putstr_fd(USAGE_EG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	// wireframe(*(argv + 1));
	exit(EXIT_SUCCESS);
}
