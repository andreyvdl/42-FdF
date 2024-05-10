/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:06:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/09 21:39:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char	*argv[])
{
	t_printf	print;

	printf_build(&print, STDERR_FILENO);
	if (argc != 2)
	{
		print.print(&print, "Usage: %s file.fdf\n", argv[0]);
		return (1);
	}
	return (0);
}
