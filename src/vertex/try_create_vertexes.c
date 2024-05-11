/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_create_vertexes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:00:33 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/11 15:03:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

bool	try_create_vertexes(t_fdf *fdf, char **points)
{
	if (ft_strlen(points[0]) == 0)
		return (false);
	fdf->vertex.add_back(&fdf->vertex, ft_lst_new(NULL));
	if (try_line_vertexes(&fdf->vertex.at(&fdf->vertex, \
	fdf->vertex._size - 1), points, fdf->vertex._size - 1))
		return (true);
	return (false);
}

/*
 * need to think better how TODO this
 * fdf->vertex[y] = vertex y axies
 * fdf->vertex[y][x] = vertex x axies
 * fdf->vertex[y][x].right = vertex right
 */

static bool	try_line_vertexes(t_list *line, char **points, size_t y)
{
	t_vertex	*tmp;
	size_t		x;

	tmp = line;
	x = 0;
	tmp->right = vertex_build(x, y, ft_atoi(points[x]), has_color(points[x]));
	if (!tmp->right)
		return (true);
	return (false);
}
