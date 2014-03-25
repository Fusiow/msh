/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 03:27:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:22:05 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/msh.h"

static char		*result_char_cmd(int fd)
{
	int		i;
	char	*result;
	int		ret;
	char	*buffer;

	i = 0;
	buffer = NULL;
	result = (char *)ft_memalloc(sizeof(char) * 1024);
	while ((ret = read(fd, result, 1024)) != 0)
	{
		result = ft_strsub(result, 0, ret);
		if (i++ == 0)
			buffer = ft_strdup(result);
		else
			buffer = ft_strjoin(buffer, result);
	}
	buffer[ft_strlen(buffer) - 1] = '\0';
	return (buffer);
}

char			*result_cmd(char *cmd)
{
	int		fd[2];
	int		pid;
	int		ret;

	if (pipe(fd) == -1)
		return (NULL);
	if (!(pid = fork()))
	{
		if (close(fd[0]) == -1)
			return (NULL);
		if (dup2(fd[1], 1) == -1)
			return (NULL);
		dup2(fd[1], 2);
		if (close(fd[1]) == -1)
			return (NULL);
		if (pre_exec_nofork(cmd))
			return (NULL);
	}
	else
	{
		waitpid(pid, &ret, WUNTRACED);
		if (close(fd[1]) == -1)
			return (NULL);
	}
	return (result_char_cmd(fd[0]));
}
