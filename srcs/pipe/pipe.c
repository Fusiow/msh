/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:54:10 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 14:28:58 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	go_pipe(char **tab)
{
	int		fd_pipe[2];
	int		fd_in;
	int		i;
	t_command	*list;

	tab = join_tab(tab);
	i = 0;
	while (tab[i])
	{
		pipe(fd_pipe);
		if (!fork())
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
			wait(0);
			close(fd_pipe[1]);
			fd_in = fd_pipe[0];
			++i;
		}
	}
	_exit(0);
}
