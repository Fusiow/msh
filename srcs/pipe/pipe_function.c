/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:46:37 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 14:20:27 by lsolofri         ###   ########.fr       */
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
