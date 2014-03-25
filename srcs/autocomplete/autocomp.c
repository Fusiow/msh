/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:13:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 11:27:33 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*argument_completion(char *str, char *cmd)
{
	int		i;
	char	*result;
	int		v;
	char	*name;
	glob_t	list;

	if (str)
	{
		i = ft_strlen(str);
		while (str[i] != ' ' && i > 0)
			--i;
		name = ft_strjoin(str, "*");
		glob(name, GLOB_NOCHECK, 0, &list);
		i = v = 0;
		if (list.gl_pathc == 0)
		{
			globfree(&list);
			return (NULL);
		}
		while (list.gl_pathv[i])
		{
			if (!ft_strncmp(list.gl_pathv[i], str, ft_strlen(str)))
			{
				++v;
				result = ft_strdup(list.gl_pathv[i]);
			}
			++i;
		}
		if (v == 1)
		{
			if (ft_strcmp(result, ft_strjoin(str, "*")) == 0)
				return (NULL);
			if (isdirectory(result))
				result = ft_strjoin(result, "/");
			else
				result = ft_strjoin(result, " ");
			globfree(&list);
			return (ft_strjoin(ft_strsub(cmd, 0, (ft_strlen(cmd) - ft_strlen(str))), result));
		}
		i = 0;
		ft_putstr("\n");
		while (list.gl_pathv[i])
		{
			if (ft_strcmp(list.gl_pathv[i], ft_strjoin(str, "*")))
			{
				aff_cmd(list.gl_pathv[i], str);
				ft_putstr("\n");
			}
			++i;
		}
		globfree(&list);
	}
	return (ft_strdup("ok"));
}

char	*spe_argument_completion(char *cmd, char *str, int x)
{
	static glob_t	list;
	static int		i;
	static int		v;
	static char		*command;
	char			*result;
	int				j;
	int				k;

	result = NULL;
	if (x == 1)
	{
		v = 0;
		globfree(&list);
		return (NULL);
	}
	if (v == 0)
	{
		++v;
		command = ft_strdup(str);
		glob(ft_strjoin(cmd, "*"), GLOB_NOCHECK, 0, &list);
	}
	if (!list.gl_pathv[i])
		i = 0;
	if (list.gl_pathc && list.gl_pathv[i])
	{
		if (!ft_strcmp(list.gl_pathv[i], ft_strjoin(cmd, "*")))
			return (str);
		j = ft_strlen(command);
		while (command[j] != ' ' && j > 0)
			--j;
		if (j > 0)
			++j;
		k = 0;
		while (command[j] == list.gl_pathv[i][k] && command[j] && list.gl_pathv[i][k])
		{
			++j;
			++k;
		}
		if (ft_strcmp(list.gl_pathv[i], ft_strjoin(cmd, "*")) == 0)
			return (str);
		result = ft_strjoin(command, ft_strsub(list.gl_pathv[i], k, ft_strlen(list.gl_pathv[i])));
		++i;
		if (ft_strlen(str) > ft_strlen(result) - 1)
		{
			j = ft_strlen(str) - ft_strlen(result);
			while (j >= 0)
			{
				ft_putstr(tgetstr("le", NULL));
				--j;
			}
		}
		else
		{
			ft_putstr(tgetstr("le", NULL));
			ft_putstr(" ");
		}
		if (list.gl_pathc == 1)
		{
			result = ft_strjoin(result, " ");
			list.gl_pathc = 0;
		}
	}
	return (result);
}
