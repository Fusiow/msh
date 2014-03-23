/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:18:15 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/23 15:11:48 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		fg_bg(t_jobs *jobs, char ** tab, int k)
{
	int		rt;
	int		i;

	rt = 0;
	i = 0;
	if (jobs == NULL)
	{
		job_error(k);
		return ;
	}
	if (tab[1])
	{
		while (tab[1] && tab[1][++i] != '\0')
			rt = ((ft_isdigit(tab[1][i])) ? 1 : 0);
		search_job(jobs, tab[1], rt);
	}
	else
	{
		while (jobs->next != NULL)
			jobs = jobs->next;
	}
	ft_putstr("[");
	ft_putnbr(jobs->job);
	ft_putstr("]");
	ft_putstr(" + ");
	ft_putstr("continued\t\t");
	ft_putendl(jobs->name);
	kill(jobs->pid, SIGCONT);
	g_jobs = remove_jobs(g_jobs, jobs->pid);
	if (k == 1)
		waitpid(jobs->pid, &rt, WUNTRACED);
	g_jobs = add_job(g_jobs, jobs->name, jobs->pid);
	check_return(rt, jobs->pid);
}

int			search_job(t_jobs *jobs, char *tab, int rt)
{
	(void)rt;
	while (jobs->next != NULL)
	{
		if (jobs->pid != ft_atoi(tab)) 
			jobs = jobs->next;
	}
//	if (jobs->pid == ft_atoi(tab))
//	{
//		kill(jobs->pid, SIGCONT);
//		wait(&jobs->pid);
//		g_jobs = remove_jobs(g_jobs, jobs->pid);
//	}
	pid_error(tab);
	return (0);
}
