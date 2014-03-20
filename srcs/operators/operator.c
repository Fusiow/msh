/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 11:59:40 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/18 21:24:31 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*split_tab(char **tab, int i)
{
	char	*beg;
	int		v;

	v = 0;
	while (v < i && tab[i])
	{
		if (v == 0)
			beg = ft_strdup(tab[v]);
		else
			beg = ft_strjoin(beg, tab[v]);
		beg = ft_strjoin(beg, " ");
		++v;
	}
	v = 0;
	++i;
	while (tab[i])
	{
		tab[v] = tab[i];
		++v;
		++i;
	}
	tab[v] = NULL;
	return (beg);
}

void	check_operators(char **tab)
{
		int		i;
		int		v;

		i = 0;
		while (tab[i])
		{
			if (!ft_strcmp(tab[i], "("))
			{
				v = i;
				while (ft_strcmp(tab[i], ")") && tab[i])
					++i;
				if (!fork())
					pre_exec(join_spe_tab(tab, v + 1, i));
				wait(0);
				_exit(0);
			}
			if (!(ft_strcmp(tab[i], "&&")))
			{
				if (pre_exec(split_tab(tab, i)))
					_exit(0);
			}
			else if (!ft_strcmp(tab[i], "&"))
			{
				pre_exec_nowait(split_tab(tab, i));
				check_operators(tab);
			}
			else if (!(ft_strcmp(tab[i], "||")))
			{
				v = pre_exec(split_tab(tab, i));
				if (v == 0 || v == 2)
					_exit(0);
			}
			++i;
		}
}
