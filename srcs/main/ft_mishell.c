/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:27 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/18 15:58:09 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	exec_cmd(char **tab)
{
	char	**exec;
	int		i;
	char	*result;

	i = 0;
	if (tab[0] != NULL)
	{
		exec = ft_strsplit(find_value_envir("PATH"), ':');
		while (exec[i])
		{
			exec[i] = ft_strjoin(exec[i], "/");
			result = ft_strjoin(exec[i++], tab[0]);
			execve(result, tab, g_env);
		}
		execve(tab[0], tab, g_env);
		ft_putendl("Not found");
	}
}
