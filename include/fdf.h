#ifndef FDF_H
# define FDF_H

/* ------------------------------------------------------------------------- */
/* INCLUDES */

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

/* ------------------------------------------------------------------------- */
/* DEFINES */

# define ERR_ARG "\e[1;31margc: 2 arguments required\e[0m\n"
# define PERR_FILE "open: open returned a error "
# define USAGE_EG "usage: \e[1;4;3;32m./fdf\e[0m \e[1;4;3;31mmap_file\e[0m\n\
\e[1;33mThe map file should end with .fdf extension\e[0m\n"

/* ------------------------------------------------------------------------- */
/* FUNCTIONS */

bool	file_is_invalid(char *file);

void	error_argc(void);
void	error_file(char *file);

/* ------------------------------------------------------------------------- */

#endif
