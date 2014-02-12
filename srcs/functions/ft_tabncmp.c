/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:29:47 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/12 19:22:26 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		ft_tabncmp(char **env, char **av)
{
	int		i;
	int		l;
	char	*tmp;

	i = -1;
	tmp = ft_strjoin(av[2], "=");
	l = ft_strlen(tmp);
	while (env[++i] && av[2] && ft_strcmp("", av[2]) != 0)
	{
		if (ft_strncmp(env[i], tmp, l) == 0)
			return (i);
	}
	return (-1);
}
