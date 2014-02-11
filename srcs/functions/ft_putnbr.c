/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:03:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/11 16:16:05 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	ft_putnbr(int nb)
{
	int		reverse_nb;

	reverse_nb = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 0)
	{
		reverse_nb *= 10;
		reverse_nb += nb % 10;
		nb /= 10;
	}
	while (reverse_nb > 0)
	{
		ft_putchar('0' + (reverse_nb % 10));
		reverse_nb /= 10;
	}
}
