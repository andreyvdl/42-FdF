/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:00:59 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 14:44:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

ssize_t	ft_atoi(const char *nptr)
{
	bool	neg;
	ssize_t	nbr;

	if (!nptr || nptr[0] == 0)
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	neg = *nptr == '-';
	nptr = nptr + 1 * (neg || *nptr == '+');
	nbr = 0;
	if (neg)
	{
		while (ft_isdigit(*nptr))
			nbr = nbr * 10 - (*nptr++ - '0');
		return (nbr);
	}
	while (ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr++ - '0');
	return (nbr);
}
