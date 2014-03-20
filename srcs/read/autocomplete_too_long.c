/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_too_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:23:11 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/03 15:03:27 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		auto_comp_choice(int i)
{
	char	buffer[1];

	ft_putstr("\nmsh: Do you wish to see all possibilities (");
	ft_putnbr(i);
	ft_putstr(" lines)? (y/n)");
	read(0, buffer, 1);
	if (buffer[0] == 'y')
		return (2);
	else
	{
		ft_putstr("\n");
		prompt();
		ft_putstr(" ");
		return (0);
	}
}
