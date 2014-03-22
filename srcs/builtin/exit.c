/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/22 13:47:48 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int				ft_exit(char **tab)
{
	int			i;
	int			rt;
	int			result;

	i = -1;
	rt = 0;
	result = 0;
	while (tab[1] && tab[1][++i] != '\0')
	{
		if (ft_isdigit(tab[1][i]))
			rt = ft_atoi(tab[1]);
		else
		{
			exit_error(tab);
			result = 1;
			break ;
		}
	}
	if (!result)
	{
		ft_putendl("Goodbye!");
		_exit(rt);
	}
	return (0);
}
