/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/21 19:19:24 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int				ft_exit(char **tab, int *rt)
{
	int			i;

	i = -1;
	while (tab[1] && tab[1][++i] != '\0')
	{
		if (ft_isdigit(tab[1][i]))
			*rt = ft_atoi(tab[1]);
		else
		{
			if (tab[1][i] != '\0')
			{
				exit_error(tab);
				*rt = 0;
				return (-1);
			}
		}
	}
	return (1);
}
