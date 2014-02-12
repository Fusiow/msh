/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:29:47 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/12 18:32:46 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		ft_tabncmp(char **env, char **av)
{
	int		i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], av[2], ft_strlen(av[2])) == 0)
			return (i);
	}
	return (0);
}
