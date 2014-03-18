/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:47:41 by aardjoun          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/03/17 20:07:55 by lsolofri         ###   ########.fr       */
=======
/*   Updated: 2014/03/17 15:25:11 by aardjoun         ###   ########.fr       */
>>>>>>> be3618efd40499c6c425a71ba2b407b1e1e4cd26
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		interrupt_process(__attribute__((unused))int s)
{
	ft_putendl("");
}

void		interrupt_cmd(__attribute__((unused))int s)
{
	ft_putendl("");
	prompt();
}

void		show_signal(int pid, int sig)
{
	ft_putstr("msh: ");
	show_stop(sig);
	ft_putstr("\t");
	ft_putendl(find_prog(g_jobs, pid));
}

void		show_interrupt(int pid)
{
	ft_putstr("msh: suspended\t");
	ft_putendl(find_prog(g_jobs, pid));
}

/*int			std_signal(__attribute__((unused))int s)
{

}*/

void	check_return(int ret, int pid)
{
	int		sig;

	sig = WTERMSIG(ret);
	if (WIFEXITED(ret))
		g_jobs = remove_jobs(g_jobs, pid);
	else if (WIFSIGNALED(ret))
	{
		if (sig == 4 || sig == 3 || sig == 6 || sig == 8 || sig == 9 || 
				sig == 15 || sig == 11 || sig == 13 || sig == 10 || sig == 7)
			show_signal(pid, sig);
		g_jobs = remove_jobs(g_jobs, pid);
	}
	else if (WIFSTOPPED(ret))
	{
		if (sig == 127 || sig == 18)
			show_interrupt(pid);
	}
}


// kill(pid, SIGCONT);
//  if (fg)
//  	wait(&pid);
//
