/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:15 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/28 17:47:14 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
