/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 11:59:40 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:51:38 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char			*split_tab(char **tab, int i)
{
	char		*beg;
	int			v;

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

static int		sub_shell(char **tab, int i)
{
	int			v;

	v = i;
	while (tab[i] && ft_strcmp(tab[i], ")"))
		++i;
	if (!fork())
		pre_exec(join_spe_tab(tab, v + 1, i));
	wait(0);
	_exit(0);
	return (i);
}

void			check_operators(char **tab, int i)
{
	int			v;

	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "("))
			i = sub_shell(tab, i);
		if (!(ft_strcmp(tab[i], "&&")))
		{
			if (pre_exec(split_tab(tab, i)))
				_exit(0);
		}
		else if (!ft_strcmp(tab[i], "&"))
		{
			pre_exec_nowait(split_tab(tab, i));
			wait(0);
			_exit(0);
		}
		else if (!(ft_strcmp(tab[i], "||")))
		{
			v = pre_exec(split_tab(tab, i));
			if (v == 0 || v == 2)
				_exit(0);
		}
	}
}
