/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 12:02:30 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 18:17:53 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int		check_option(char **tab)
{
	int			opt;
	int			i;
	int			j;

	i = 0;
	opt = 0;
	while (tab[++i] && (ft_strncmp(tab[i], "-", 1) == 0))
	{
		j = 0;
		while (tab[i][j])
		{
			if (opt == 3)
				break ;
			if (tab[i][j] == 's' && tab[i][j + 1] == '\0')
				opt = ((opt == 2) ? 3 : 1);
			if (tab[i][j] == 'n' && tab[i][j + 1] == '\0')
				opt = ((opt == 1) ? 3 : 2);
			if (tab[i][j] == 'n' && tab[i][j + 1] == 's')
				opt = 3;
			if (tab[i][j] == 's' && tab[i][j + 1] == 'n')
				opt = 3;
			j++;
		}
	}
	return (opt);
}

static void		ft_print_tab(char **tab, int i, int nb, int k)
{
	while (i < nb && tab[i] && ft_strcmp(tab[i], "|"))
	{
		ft_putstr(tab[i]);
		if ((k == 0 || k == 2) && i < (nb - 1))
			ft_putchar(' ');
		i++;
	}
}

void			ft_echo(char **tab)
{
	int			nb;
	int			i;
	int			opt;

	opt = check_option(tab);
	nb = ft_tablen(tab);
	i = 1;
	while (ft_strncmp(tab[i], "-", 1) == 0)
		i++;
	ft_print_tab(tab, i, nb, opt);
	i = 1;
	if (opt == 2 || opt == 3)
		return ;
	ft_putchar('\n');
}
