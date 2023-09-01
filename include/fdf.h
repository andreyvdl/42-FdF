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
\e[1;33mThe map file should be a `.fdf` extension\e[0m\n"

/* ------------------------------------------------------------------------- */
/* TYPEDEFS */

/**
 * @brief Structure that stores the map data
 * 
 * @param x The x position of the point
 * @
 */
typedef struct s_map	t_map;

/**
 * @brief Structure that stores generic info
 * 
 * @param biggest_line The biggest line of the map
 * @param biggest_column The biggest column of the map
 */
typedef struct s_info	t_info;

/**
 * @brief Main structure of the program
 * 
 * @param **map The t_map struct;
 * @param info the t_info struct;
 */
typedef struct s_fdf	t_fdf;

struct	s_map
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	z;
	uint32_t	color;
};

struct	s_info
{
	size_t	biggest_line;
	size_t	biggest_column;
};

struct	s_fdf
{
	t_map	**map;
	t_info	info;
};

/* ------------------------------------------------------------------------- */
/* FUNCTIONS */

bool	file_is_invalid(char *file);

void	error_argc(void);
void	error_file(char *file);

/* ------------------------------------------------------------------------- */

#endif
