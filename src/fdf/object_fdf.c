/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:56:41 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/10 17:18:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_fdf	fdf_build(t_fdf *fdf)
{
	t_fdf	tmp;

	ft_bzero(&tmp.obj_mlx, sizeof(t_mlx));
	tmp.vertex = NULL;
	printf_build(&tmp.printf, STDERR_FILENO);
	gnl_build(&tmp.gnl, STDIN_FILENO);
	if (fdf)
		*fdf = tmp;
	return (tmp);
}

void	fdf_unbuild(t_fdf *fdf)
{
	if (fdf->vertex)
		vertex_unbuild(fdf->vertex);
	gnl_unbuild(&fdf->gnl);
}
