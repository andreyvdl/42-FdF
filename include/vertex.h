/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:18:44 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/10 17:01:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H
# include "fdf.h"

typedef struct s_vertex	t_vertex;

struct s_vertex
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	t_vertex	*up;
	t_vertex	*down;
	t_vertex	*left;
	t_vertex	*right;
};

t_vertex	*vertex_build(int x, int y, int z, uint32_t color);
void		vertex_unbuild(t_vertex *vertex);

#endif