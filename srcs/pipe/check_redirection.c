/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:32:03 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/03 13:24:15 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		check_redirection(char **tab)
{
	int		i;
	int		v;

	i = 0;
	v = -1;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "<"))
		{
			infile(tab[i + 1]);
			re_tab(tab, i);
		}
		else
			++i;
	}
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "<<"))
		{
			if (v != -1)
			{
				re_tab(tab, v);
				i -= 2;
			}
			v = i;
		}
		++i;
	}
	if (v != -1)
	{
		spe_infile(tab[v + 1]);
		re_tab(tab, v);
	}
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], ">"))
		{
			outfile(tab[i + 1]);
			re_tab(tab, i);
		}
		else
			++i;
	}
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], ">>"))
		{
			spe_outfile(tab[i + 1]);
			re_tab(tab, i);
		}
		else
			++i;
	}
	i = 0;
	while (tab[i] && ft_strcmp(tab[i], "|"))
		++i;
	if (tab[i])
	{
		go_pipe(tab);
		return (0);
	}
	return (1);
}
