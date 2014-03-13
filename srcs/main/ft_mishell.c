/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:27 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/13 13:10:28 by lsolofri         ###   ########.fr       */
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
	_exit(1);
}

int		pre_exec(char *str)
{
	t_command	*tmp;
	pid_t		pid;

	tmp = quick_parse(str);
	while (tmp)
	{
		if (tmp->cmd[0])
		{
			tmp->cmd = is_alias(g_alias, tmp->cmd);
			if (detect_built(tmp->cmd))
			{
				if (!(pid = fork()))
				{
					check_operators(tmp->cmd);
					check_redirection(tmp->cmd);
					exec_cmd(tmp->cmd);
				}
				else
				{
					signal(SIGINT, interrupt_process);
					wait(&pid);
				}
			}
		}
		tmp = tmp->next;
	}
	return (pid);
}
