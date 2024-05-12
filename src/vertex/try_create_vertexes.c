/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_create_vertexes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:00:33 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/12 15:47:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

bool	try_create_vertexes(t_fdf *fdf, char **points)
{
	size_t		y;
	t_vertex	*top_left;

	if (!points[1])
		return (false);
	y = 0;
	top_left = fdf->vertexes;
	while (top_left)
	{
		if (top_left->down)
			top_left = top_left->down;
		else
			break ;
		++y;
	}
	if (try_build_line(&top_left, points, y))
		return (true);
	if (y == 0)
		fdf->vertexes = top_left;
	return (false);
}

