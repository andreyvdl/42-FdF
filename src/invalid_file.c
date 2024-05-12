/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:44:15 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/12 15:47:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static bool	filename_errors(char *filename);
static bool	file_misconfiguration(t_fdf *fdf);

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
	if (file_misconfiguration(fdf))
	{
		fdf->printf.print(&fdf->printf, "[file] error\n");
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

static bool	file_misconfiguration(t_fdf *fdf)
{
	char	*line[2];
	char	**splited;

	line[0] = fdf->gnl.get_line(&fdf->gnl);
	while (line[0])
	{
		line[1] = ft_strtrim(line[0], " \t\n");
		free(line[0]);
		if (!line[1])
			return (true);
		splited = ft_split(line[1], ' ');
		free(line[1]);
		if (!splited)
			return (true);
		else if (try_create_vertexes(fdf, splited))
		{
			free_matrix(splited);
			return (true);
		}
		free_matrix(splited);
		line[0] = fdf->gnl.get_line(&fdf->gnl);
	}
	return (false);
}
