/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 18:01:09 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/02 18:03:16 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**ft_tabdup(char **src)
{
	int		i;
	char	**result;

	i = ft_tablen(src);
	result = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (src[i])
	{
		result[i] = ft_strdup(src[i]);
		++i;
	}
	result[i] = NULL;
	return (result);
}
