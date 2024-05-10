/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:44:15 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/10 18:00:04 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static bool	filename_errors(char *filename);

bool	invalid_file(t_fdf *fdf, char *filename)
{
	if (filename_errors(filename))
	{
		fdf->printf.print(&fdf->printf, "[filename] error\n");
		return (true);
	}
	fdf->gnl.set_fd(&fdf->gnl, open(filename, O_RDONLY));
	if (fdf->gnl._fd < 0)
	{
		fdf->printf.print(&fdf->printf, "[open] error\n");
		return (true);
	}
	return (false);
}

static bool	filename_errors(char *filename)
{
	if (ft_strlen(filename) < 5)
		return (true);
	else if (!ft_strchr(filename, '.'))
		return (true);
	else if (ft_strncmp(ft_strrchr(filename, '.'), ".fdf", sizeof(".fdf")))
		return (true);
	return (false);
}
