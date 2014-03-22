/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 03:27:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/22 11:25:39 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*result_cmd(char *cmd)
{
	char    *result;
	int     fd[2];
	int     ret;
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	if (pipe(fd) == -1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * 1024);
	if (!result)
		return (NULL);
	if (fork() == 0)
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
		wait(0);
		if (close(fd[1]) == -1)
			return (NULL);
		while ((ret = read(fd[0], result, 1024)) != 0)
		{
			result = ft_strsub(result, 0, ret);
			if (i++ == 0)
				buffer = ft_strdup(result);
			else
				buffer = ft_strjoin(buffer, result);
		}
	}
	buffer[ft_strlen(buffer) - 1] = '\0';
	return (buffer);
}
