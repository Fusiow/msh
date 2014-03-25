/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:15 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 18:20:38 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			search_jobs(t_jobs *list, int pid)
{
	t_jobs	*tmp;

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
	int		pid;
	int		ret;

	ret = 0;
	pid = 0;
	if (jobs == NULL)
	{
		job_error(k);
		return ;
	}
	if (tab[1])
	{
		if (is_digit(tab[1]) == 0)
		{
			pid_error(tab[1]);
			return ;
		}
	}
	else
		pid = find_pid(g_jobs);
	job_continued(jobs->job, jobs->name);
	kill(pid, SIGCONT);
	waitpid(pid, &ret, WUNTRACED);
	check_return(ret, pid);
}

void		job_continued(int job, char *name)
{
	ft_putstr("[");
	ft_putnbr(job);
	ft_putstr("]");
	ft_putstr(" + ");
	ft_putstr("continued\t\t");
	ft_putendl(name);
}

int			is_digit(char *tab)
{
	int		i;
	int		pid;

	pid = 0;
	i = 0;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			pid = 1;
		++i;
	}
	if (pid == 1)
		return (0);
	else
		pid = search_jobs(g_jobs, ft_atoi(tab));
	return (pid);
}

int			find_pid(t_jobs *jobs)
{
	while (jobs->next != NULL)
		jobs = jobs->next;
	return (jobs->pid);
}
