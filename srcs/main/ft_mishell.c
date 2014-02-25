/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:27 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/25 02:33:58 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	exec_cmd(char **tab)
{
	char	**exec;
	int		i;
	char	*result;
	char	**env;

	i = 0;
	env = make_env_tab(g_env);
	exec = ft_strsplit(find_value_envir(g_env, "PATH"), ':');
	while (exec[i])
	{
		exec[i] = ft_strjoin(exec[i], "/");
		result = ft_strjoin(exec[i++], tab[0]);
		execve(result, tab, env);
	}
	execve(tab[0], tab, env);
	unknow_cmd(tab[0]);
}

void	pre_exec(char **tmp, int *rt, int *ret)
{
	if (detect_built(rt, tmp, ret))
	{
		if (fork())
			wait(0);
		else
			exec_cmd(tmp);
	}
}
