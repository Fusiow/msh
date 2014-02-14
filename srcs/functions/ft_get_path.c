/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 14:35:34 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/14 16:05:18 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char		**ft_get_path(char **env, char *commande)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i] && (ft_strncmp("PATH=", env[i], 5)))
		i++;
	path = ft_strsplit(&env[i][5], ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], commande);
		i++;
	}
	return (path);
}
