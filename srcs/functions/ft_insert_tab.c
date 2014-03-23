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
	char	*result;
	t_command	*list;

	if (i == 0)
	{
		result = join_tab2(alias);
		if (src[1])
		{
			result = ft_strjoin(result, join_tab_spe(src, 1, ft_tablen(src)));
		}
	}
	else if (!src[i + 1])
	{
		result = join_tab_spe(src, 0, ft_tablen(src) - 1);
		result = ft_strjoin(result, join_tab2(alias));
	}
	else
	{
		result = join_tab_spe(src, 0, i);
		result = ft_strjoin(result, join_tab2(alias));
		result = ft_strjoin(result, join_tab_spe(src, i + 1, ft_tablen(src)));
	}
	list = quick_parse(result);
	return (list->cmd);
}
