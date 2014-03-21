/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 14:18:25 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/21 13:43:21 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_jobs		*add_job(t_jobs *list, char *name, int pid)
{
	t_jobs	*tmp;
	t_jobs	*tmp2;

	tmp2 = list;
	tmp = (t_jobs *)malloc(sizeof(t_jobs));
	tmp->name = ft_strdup(name);
	tmp->pid = pid;
	tmp->job = 1;
	tmp->status = 0;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->job = tmp2->job + 1;
	return (list);
}

void		show_jobs(t_jobs *jobs)
{
	int		i;

	i = 0;
	while (jobs)
	{
		ft_putstr("[");
		ft_putnbr(jobs->job);
		ft_putstr("] ");
		ft_putstr("[");
		ft_putnbr(jobs->pid);
		ft_putstr("]\t");
		ft_putstr("-\t");
		ft_putendl(jobs->name);
		jobs = jobs->next;
		++i;
	}
}

char	*find_prog(t_jobs *jobs, int pid)
{
	while (jobs && jobs->pid != pid)
		jobs = jobs->next;
	if (jobs)
		return (jobs->name);
	return (NULL);
}

t_jobs		*remove_jobs(t_jobs *jobs, int pid)
{
	t_jobs	*tmp;

	if (!jobs)
		return (NULL);
	if (jobs->pid == pid)
	{
		tmp = jobs->next;
		free(jobs);
		tmp = remove_jobs(tmp, pid);
	}
	else
	{
		jobs->next = remove_jobs(jobs->next, pid);
		return (jobs);
	}
	return (NULL);
}
