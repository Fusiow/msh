/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:54:10 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 15:40:00 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	go_pipe(char **tab2)
{
	int		fd_pipe[2];
	int		fd_in;
	int		i;
	char	**tab;
	t_command	*list;
	int			pid;

	tab = join_tab(tab2);
	ft_free_tab(tab2);
	i = 0;
	while (tab[i])
	{
		pipe(fd_pipe);
		if (!(pid = fork()))
		{
			dup2(fd_in, 0);
			if (tab[i + 1])
				dup2(fd_pipe[1], 1);
			close(fd_pipe[0]);
			list = quick_parse(tab[i]);
			exec_cmd(list->cmd);
		}
		else
		{
			close(fd_pipe[1]);
			fd_in = fd_pipe[0];
			++i;
		}
	}
	waitpid(pid, &i, WUNTRACED);
	check_return(i, pid);
	ft_free_tab(tab);
	_exit(0);
}
