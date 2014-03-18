/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:46:37 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/18 17:35:03 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**join_tab(char **tab)
{
	char	*result;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
			result = ft_strdup(tab[i]);
		else
			result = ft_strjoin(result, tab[i]);
		result = ft_strjoin(result, " ");
		++i;
	}
	return (ft_strsplit(result, '|'));
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
