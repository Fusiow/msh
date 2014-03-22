/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:46:37 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/22 11:21:40 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**join_tab(char **tab)
{
	char	*result;
	char	**result_tab;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
			result = ft_strdup(tab[i]);
		else
			result = ft_strjoin(result, tab[i]);
		if (tab[i + 1])
			result = ft_strjoin(result, " ");
		++i;
	}
	result_tab = ft_strsplit(result, '|');
	return (result_tab);
}

char	*join_spe_tab(char **tab, int beg, int end)
{
	char	*result;

	result = NULL;
	while (beg < end)
	{
		if (!result)
			result = ft_strjoin(tab[beg], " ");
		else
			result = ft_strjoin(ft_strjoin(" ", result), tab[beg]);
		beg++;
	}
	return (result);
}
