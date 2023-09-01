#include "../include/fdf.h"

void	error_argc(void)
{
	ft_putstr_fd(ERR_ARG, STDERR_FILENO);
	ft_putstr_fd(USAGE_EG, STDERR_FILENO);
}
