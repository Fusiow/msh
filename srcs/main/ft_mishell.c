/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mishell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:59:27 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/28 23:44:02 by lsolofri         ###   ########.fr       */
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
	_exit(0);
}

void	pre_exec(char *str, int *rt, int *ret)
{
	char	*result;
	t_command	*tmp;
	t_command	*beg;

	tmp = quick_parse(str);
	beg = tmp;
	while (tmp)
	{
		result = is_alias(g_alias, tmp->cmd[0]);
		if (result)
		{
			tmp = beg;
			ft_free_cmd_list(tmp);
			tmp = quick_parse(result);
			beg = tmp;
		}
		if (detect_built(rt, tmp->cmd, ret))
		{
			if (fork())
			{
				signal(SIGINT, interrupt_process);
				wait(0);
			}
			else
			{
				check_redirection(tmp->cmd);
				exec_cmd(tmp->cmd);
			}
		}
		tmp = tmp->next;
	}
	tmp = beg;
	if (tmp)
		ft_free_cmd_list(tmp);
	tmp = NULL;
}
