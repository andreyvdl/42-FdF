/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:19:23 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/11 14:28:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "../libft/headers/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "vertex.h"
# include "object_mlx.h"

typedef struct s_fdf
{
	t_flist		vertex;
	t_mlx		obj_mlx;
	t_printf	printf;
	t_gnl		gnl;
}	t_fdf;

t_fdf	fdf_build(t_fdf *fdf);
void	fdf_unbuild(t_fdf *fdf);

void	free_matrix(char **matrix);

bool	invalid_file(t_fdf *fdf, char *filename);

#endif
