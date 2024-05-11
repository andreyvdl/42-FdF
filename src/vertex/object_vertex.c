/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_vertex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:47:12 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/11 13:19:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_vertex	*vertex_build(int x, int y, int z, uint32_t color)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	if (!vertex)
		return (NULL);
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	vertex->color = color;
	vertex->down = NULL;
	vertex->right = NULL;
	return (vertex);
}

void	vertex_unbuild(void *content)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)content;
	if (vertex->next)
		vertex_unbuild(vertex->next);
	free(vertex);
}
