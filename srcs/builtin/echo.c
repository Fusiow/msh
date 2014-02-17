/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 12:02:30 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/17 14:18:12 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int		checkspace(char **tab)
{
	int			sp;
	int			i;

	i = 0;
	sp = 0;
	while (tab[i])
		sp = ((ft_strncmp(tab[i++], "-s", 2) == 0) ? 1 : sp);
	return (sp);
}

static void		ft_print_tab(char **tab, int i, int nb)
{
	while (i < nb && tab[i])
	{
		ft_putstr(tab[i]);
		if (checkspace(tab) == 0 && i < (nb - 1))
			ft_putchar(' ');
		i++;
	}
}

void			ft_echo(char **tab)
{
	int			nb;
	int			i;

	nb = ft_tablen(tab);
	i = 1;
	while (ft_strncmp(tab[i], "-", 1) == 0)
		i++;
	ft_print_tab(tab, i, nb);
	i = 1;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], "-n", 2) == 0 && i < nb)
			break ;
		else
		{
			ft_putchar('\n');
			break ;
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	ft_echo(av);
	if (ac < 2)
		ft_putchar('\n');
	return (0);
}
