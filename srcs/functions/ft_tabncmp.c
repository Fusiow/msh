/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:29:47 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/21 19:11:51 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		ft_tabncmp(char **env, char **av)
{
	int		i;
	int		l;
	char	*tmp;

	i = -1;
	tmp = ft_strjoin(av[1], "=");
	l = ft_strlen(tmp);
	while (env[++i] && av[1] && ft_strcmp("", av[1]) != 0)
	{
		if (ft_strncmp(env[i], tmp, l) == 0)
			return (i);
	}
	return (-1);
}
