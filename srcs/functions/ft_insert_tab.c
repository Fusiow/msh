/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 14:18:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:23:31 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**ft_insert_tab(char **src, char **alias, int i)
{
	char	**res;
	int		j;
	int		v;
	int		x;

	j = 0;
	x = 0;
	v = 0;
	res = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(src) +
				ft_tablen(alias)));
	while (j < (ft_tablen(src) + ft_tablen(alias)))
	{
		if (j == i)
		{
			++v;
			while (alias[x])
				res[j++] = alias[x++];
		}
		else
			res[j++] = ft_strdup(src[v++]);
	}
	res[j - 1] = NULL;
	return (res);
}
