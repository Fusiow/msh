/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_autocomp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:22:24 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:46:57 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void			do_left(char *str, char *result)
{
	int				j;

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
}

static char			*return_spe_arguments(char *p, char *cmd, char *coma,
		char *str)
{
	int				k;
	int				j;
	char			*result;

	result = NULL;
	if (p)
	{
		if (!ft_strcmp(p, ft_strjoin(cmd, "*")))
			return (str);
		j = ft_strlen(coma);
		while (coma[j] != ' ' && j > 0)
			--j;
		if (j > 0)
			++j;
		k = -1;
		while (coma[j] == p[++k] && coma[j] && p[k])
			++j;
		if (ft_strcmp(p, ft_strjoin(cmd, "*")) == 0)
			return (str);
		result = ft_strjoin(coma, ft_strsub(p, k, ft_strlen(p)));
		do_left(str, result);
	}
	return (result);
}

static char			*v_equal_zero(glob_t *list, int *v)
{
	*v = 0;
	if (list)
	{
		globfree(list);
		list = NULL;
	}
	return (NULL);
}

static int			make_glob_list(char *cmd, glob_t *list)
{
	glob(ft_strjoin(cmd, "*"), GLOB_NOCHECK, 0, list);
	return (1);
}

char				*spe_argument_completion(char *cmd, char *str, int x)
{
	static glob_t	list;
	static int		i;
	static int		v;
	static char		*command;
	char			*result;

	result = NULL;
	if (x == 1)
		return (v_equal_zero(&list, &v));
	if (v == 0)
	{
		command = ft_strdup(str);
		v = make_glob_list(cmd, &list);
	}
	i = (list.gl_pathv[i] ? i : 0);
	if (list.gl_pathc && list.gl_pathv[i])
	{
		result = return_spe_arguments(list.gl_pathv[i++], cmd, command, str);
		if (list.gl_pathc == 1)
		{
			result = ft_strjoin(result, " ");
			list.gl_pathc = 0;
		}
	}
	return (result);
}
