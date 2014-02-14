/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:27 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/14 16:30:03 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		ft_mishell(char *line)
{
	pid_t	father;
	char	**path;
	char	**tab;
	int		i;

	i = 0;
	if (line)
	{
		tab = ft_strsplit(line, ' ');
		path = ft_get_path(g_env, tab[0]);
		father = fork();
		if (father)
		{
			wait(0);
			return ;
		}
		else
			while(path[i])
				execve(path[i++], tab, g_env);
		write(1, "command not found:", 18);
	}
}
