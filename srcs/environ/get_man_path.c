/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_man_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:04:37 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/14 10:27:31 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*get_man_path(void)
{
	char	*cmd[] = {"/usr/bin/man", "--path", NULL};
	char	*result;
	int		fd[2];
	int		ret;

	if (pipe(fd) == -1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * 150);
	if (!result)
		return (NULL);
	if (fork() == 0)
	{
		if (close(fd[0]) == -1)
			return (NULL);
		if (dup2(fd[1], 1) == -1)
			return (NULL);
		if (close(fd[1]) == -1)
			return (NULL);
		if (execve(cmd[0], cmd, NULL) == -1)
			return (NULL);
	}
	else
	{
		if (close(fd[1]) == -1)
			return (NULL);
		if ((ret = read(fd[0], result, 150)) != 0)
			result[ret - 1] = '\0';
	}
	return (result);
}
