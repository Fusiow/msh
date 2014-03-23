/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:15 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/23 17:53:13 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		search_jobs(t_jobs *list, int pid)
{
	t_jobs		*tmp;

	tmp = g_jobs;
	if (list)
	{
			while (tmp && tmp->pid != pid)
				tmp = tmp->next;
		if (tmp)
			return (tmp->pid);
		else
			return (0);
	}
	return (0);
}

void		fg_bg(t_jobs *jobs, char **tab, int k)
{
	int		ret;
	int		i;
	int		pid;

	ret = 0;
	i = 0;
	if (jobs == NULL)
	{
		job_error(k);
		return ;
	}
	if (tab[1])
	{
		while (tab[1][i])
		{
			if (!ft_isdigit(tab[1][i]))
				ret = 1;
			++i;
		}
		if (ret == 1)
		{
			pid_error(tab[1]);
			return ;
		}
		else
			pid = search_jobs(g_jobs, ft_atoi(tab[1]));
	}
	else
	{
		while (jobs->next != NULL)
			jobs = jobs->next;
		pid = jobs->pid;
	}
	if (pid == 0)
	{
		pid_error(tab[1]);
		return ;
	}
	ft_putstr("[");
	ft_putnbr(jobs->job);
	ft_putstr("]");
	ft_putstr(" + ");
	ft_putstr("continued\t\t");
	ft_putendl(jobs->name);
	kill(pid, SIGCONT);
	if (k == 1)
		waitpid(pid, &ret, WUNTRACED);
	check_return(ret, pid);
}
