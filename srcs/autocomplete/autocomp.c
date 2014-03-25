/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:13:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 14:50:11 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void		show_argument_completion(char **tab, char *str)
{
	int		i;

	i = 0;
	ft_putstr("\n");
	while (tab[i])
	{
		if (ft_strcmp(tab[i], ft_strjoin(str, "*")))
		{
			aff_cmd(tab[i], str);
			ft_putstr("\n");
		}
		++i;
	}
}

static char		*search_argument(char **tab, char *str, int *v)
{
	int		i;
	char	*result;

	result = NULL;
	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], str, ft_strlen(str)))
		{
			++*v;
			result = ft_strdup(tab[i]);
		}
		++i;
	}
	return (result);
}

static char		*return_arguments(char *res, char *str, glob_t list, char *cmd)
{

	if (ft_strcmp(res, ft_strjoin(str, "*")) == 0)
		return (NULL);
	if (isdirectory(res))
		res = ft_strjoin(res, "/");
	else
		res = ft_strjoin(res, " ");
	globfree(&list);
	return (ft_strjoin(ft_strsub(cmd, 0, (ft_strlen(cmd) - ft_strlen(str))),
				res));
}

char	*argument_completion(char *str, char *cmd)
{
	int		i;
	char	*result;
	int		v;
	char	*name;
	glob_t	list;

	i = ft_strlen(str);
	while (str[i] != ' ' && i > 0)
		--i;
	name = ft_strjoin(str, "*");
	glob(name, GLOB_NOCHECK, 0, &list);
	v = 0;
	if (list.gl_pathc == 0)
	{
		globfree(&list);
		return (NULL);
	}
	result = search_argument(list.gl_pathv, str, &v);
	if (v == 1)
		return (return_arguments(result, str, list, cmd));
	show_argument_completion(list.gl_pathv, str);
	globfree(&list);
	return (ft_strdup("ok"));
}
