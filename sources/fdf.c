#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		error_argc();
		exit(EXIT_FAILURE);
	}
	else if (file_is_invalid(*(argv + 1)))
	{
		error_file(*(argv + 1));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
