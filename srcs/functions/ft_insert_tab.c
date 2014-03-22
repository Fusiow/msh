/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:18:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/23 21:46:22 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
#include <stdio.h>

char	*join_tab_spe(char **tab, int start, int end)
{
	char	*result;

	result = NULL;
	if (tab[start])
	{
		while (start < end)
		{
			if (!result)
				result = ft_strjoin(tab[start], " ");
			else
				result = ft_strjoin(ft_strjoin(" ", result), ft_strjoin(tab[start], " "));
			start++;
		}
	}
	return (result);
}

char	*join_tab2(char **tab)
{
	char	*result;

	result = NULL;
	while (*tab)
	{
		if (!result)
			result = ft_strjoin(ft_strdup(*tab), " ");
		else
			result = ft_strjoin(ft_strjoin(" ", result), ft_strjoin(*tab, " "));
		tab++;
	}
	return (result);
}

char	**ft_insert_tab(char **src, char **alias, int i)
{
	char	**result;
	int		j;
	int		v;
	int		x;

	j = 0;
	v = 1;
	x = 0;
	result = (char **)malloc(sizeof(char *) * (ft_tablen(src) + ft_tablen(alias)));
	while (j < (ft_tablen(src) + ft_tablen(alias)))
	{
		if (j == i)
		{
			while (alias[x])
			{
				result[j] = alias[x];
				++j;
				++x;
			}
		}
		else
		{
			result[j] = ft_strdup(src[v]);
			++j;
			++v;
		}
	}
	result[j - 1] = NULL;
	return (result);
}
