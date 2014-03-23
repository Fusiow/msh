/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgary <rgary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 09:58:29 by rgary             #+#    #+#             */
/*   Updated: 2014/03/23 14:36:22 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/msh.h"

char	*ft_uitoa(unsigned long n)
{
	char	*p;

	p = (char *)ft_memalloc(sizeof(char) * 22);
	p = p + 21;
	if (n == 0)
		*p = n + 48;
	while (n != 0)
	{
		*--p = (n % 10) + 48;
		n /= 10;
	}
	return (p);
}

char	*ft_itoa(long n)
{
	char	*p;

	p = (char *)ft_memalloc(sizeof(char) * 22);
	p = p + 21;
	if (n >= 0)
	{
		if (n == 0)
			*p = n + 48;
		while (n != 0)
		{
			*--p = '0' + (n % 10);
			n /= 10;
		}
		return (p);
	}
	else
	{
		while (n != 0)
		{
			*--p = '0' - (n % 10);
			n /= 10;
		}
		*--p = '-';
	}
	return (p);
}
