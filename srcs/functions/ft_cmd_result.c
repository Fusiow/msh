/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 03:27:59 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 03:40:01 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*result_cmd(char **cmd)
{
	char    *result;
	int     fd[2];
	int     ret;

	if (pipe(fd) == -1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * 1500);
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
		if (execve(cmd[0], cmd, make_env_tab(g_env)) == -1)
			return (NULL);
	}
	else
	{
		wait(0);
		if (close(fd[1]) == -1)
			return (NULL);
		if ((ret = read(fd[0], result, 1500)) != 0)
			result[ret - 1] = '\0';
	}
	return (result);
}