#include "../include/fdf.h"

static void	error_argc(void)
{
	ft_putstr_fd(ARG_ERROR, STDERR_FILENO);
	ft_putstr_fd(USAGE_EG, STDERR_FILENO);
	exit(1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		error_argc();
	
	exit(0);
}
