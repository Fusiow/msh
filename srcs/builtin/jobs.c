/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:15 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/18 17:17:07 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
/*
void		new_job(char *name, int job, int pid, int status)
{
	t_jobs	*jobs;

	jobs->name = ft_strdup(name);
	jobs->job = job;
	job->pid = pid;
	job->status = status;
	job->next = NULL;
}

t_jobs		*add_job(t_jobs *jobs, char *name, int job, int pid, int status)
{
	t_jobs	*tmp;

	tmp = new_job(name, job, pid, status);
	if (jobs == NULL)
		jobs = tmp;
	else
		while (jobs->next != NULL)
			jobs = jobs->next;
	tmp->next = jobs;
	return (jobs);
}
*/
void		fg_bg(t_jobs *jobs, char ** tab, int k)
{
	int		rt;
	int		i;

	(void)k;
	rt = 0;
	i = 0;
	if (tab[1])
	{
		while (tab[1] && tab[1][++i] != '\0')
		{
			if (ft_isdigit(tab[1][i]))
				rt = 1;
			else
				rt = 0;
		}
		search_job(jobs, tab[1], rt);
	}
	else
	{
		while (jobs->next != NULL)
			jobs = jobs->next;
		kill(jobs->pid, SIGCONT);
	}
}

int			search_job(t_jobs *jobs, char *tab, int rt)
{
	(void)tab;
	(void)rt;
	while (jobs->next != NULL)
		jobs = jobs->next;
	kill(jobs->pid, SIGCONT);
	wait(&jobs->pid);
	return (0);
}
