/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:32:03 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 22:34:13 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	check_doutredir(char **tab, int *i)
{
	while (tab[*i])
	{
		if (!ft_strcmp(tab[*i], ">>"))
		{
			spe_outfile(tab[*i + 1]);
			re_tab(tab, *i);
		}
		else
			++*i;
	}
	*i = 0;
}

void	check_outredir(char **tab, int *i)
{
	while (tab[*i])
	{
		if (!ft_strcmp(tab[*i], ">"))
		{
			outfile(tab[*i + 1]);
			re_tab(tab, *i);
		}
		else
			++*i;
	}
	*i = 0;
}

void	check_inredir(char **tab, int *i)
{
	while (tab[*i])
	{
		if (!ft_strcmp(tab[*i], "<"))
		{
			infile(tab[*i + 1]);
			re_tab(tab, *i);
		}
		else
			++*i;
	}
	*i = 0;
}

void	check_dinredir(char **tab, int *i, int *v)
{
	if (!tab[*i])
	{
		pre_exec("cat");
		_exit(0);
	}
	while (tab[*i])
	{
		if (!ft_strcmp(tab[*i], "<<"))
		{
			if (*v != -1)
			{
				re_tab(tab, *v);
				*i -= 2;
			}
			*v = *i;
		}
		++*i;
	}
	*i = 0;
}

int		check_redirection(char **tab)
{
	int		i;
	int		v;

	i = 0;
	v = -1;
	check_inredir(tab, &i);
	check_dinredir(tab, &i, &v);
	if (v != -1)
	{
		spe_infile(tab[v + 1]);
		re_tab(tab, v);
	}
	check_outredir(tab, &i);
	check_doutredir(tab, &i);
	while (tab[i] && ft_strcmp(tab[i], "|"))
		++i;
	if (tab[i])
	{
		go_pipe(tab);
		return (0);
	}
	return (1);
}
