/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:06:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/10 18:00:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char	*argv[])
{
	t_fdf	fdf;

	fdf = fdf_build(NULL);
	if (argc != 2)
	{
		fdf.printf.print(&fdf.printf, "[argument] error\n");
		fdf_unbuild(&fdf);
		return (1);
	}
	if (invalid_file(&fdf, argv[1]))
	{
		fdf_unbuild(&fdf);
		return (1);
	}
	if (render_fdf(&fdf))
	{
		fdf_unbuild(&fdf);
		return (1);
	}
	fdf_unbuild(&fdf);
	return (0);
}
