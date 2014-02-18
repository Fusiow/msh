/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/18 14:43:21 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int				ft_exit(char *str, int *rt)
{
	char		**tab;
	int			i;
	i = 0;
	if (str != NULL)
	{
		tab = ft_strsplit(str, ' ');
		if (ft_strcmp(tab[0], "exit") == 0 && tab[1])
		{
			while (tab[1][i] != '\0')
			{
				if (!(ft_isdigit(tab[1][i])))
				{
					if (tab[1][i] == '\0')
						*rt = ft_atoi(tab[1]);
					else
						*rt = 0;
				}
				i++;
			}
			return (1);
		}
	}
	return (0);
}
