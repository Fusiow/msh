/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:34:13 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/26 02:40:23 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	ft_redirloop(char *buffer, char *str, char *result, int *fd_pipe)
{
	int		i;

	i = 0;
	while (1)
	{
		ft_putstr("manual_entry>");
		buffer = take_cmd(1);
		if (ft_strcmp(buffer, str))
		{
			if (i == 0)
				result = ft_strdup(buffer);
			else
				result = ft_strjoin(ft_strjoin(result, "\n"), buffer);
			write(fd_pipe[1], buffer, ft_strlen(buffer));
			write(fd_pipe[1], "\n", 1);
		}
		else
			break ;
		buffer = NULL;
		++i;
	}
}

void	infile(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		err_no_file(str);
		_exit(0);
	}
	else
		dup2(fd, 0);
	close(fd);
}

void	spe_infile(char *str)
{
	char	*buffer;
	int		fd_pipe[2];
	char	*result;

	buffer = NULL;
	result = NULL;
	if (pipe(fd_pipe))
		return ;
	ft_redirloop(buffer, str, result, fd_pipe);
	close(fd_pipe[1]);
	dup2(fd_pipe[0], 0);
	close(fd_pipe[0]);
}

void	outfile(char *str)
{
	int		fd;

	fd = open(str, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	dup2(fd, 1);
	close(fd);
}

void	spe_outfile(char *str)
{
	int		fd;

	fd = open(str, O_APPEND | O_WRONLY | O_CREAT, 0777);
	dup2(fd, 1);
	close(fd);
}
