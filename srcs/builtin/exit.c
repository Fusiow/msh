/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/18 15:56:37 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int				ft_exit(char **tab, int *rt)
{
	int			i;

	i = -1;
	if (tab[0] != NULL)
	{
		if (ft_strcmp(tab[0], "exit") == 0)
		{
			while (tab[1] && tab[1][++i] != '\0')
			{
				if (ft_isdigit(tab[1][i]))
					*rt = ft_atoi(tab[1]);
				else
				{
					if (tab[1][i] != '\0')
					{
						exit_error(tab);
						return (-1);
					}
				}
			}
			return (1);
		}
	}
	return (0);
}
