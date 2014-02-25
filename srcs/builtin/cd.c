
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/24 20:34:56 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char		*simplify_pwd(char *tmp, char *tab, int *w)
{
/*
** non fini
*/
	int		i;
	int		k;

	k = 0;
	while (ft_strncmp("..", tab,2) == 0)
	{
		i = ft_strlen(tmp);
		while (tmp[i] != '/')
			i--;
		tmp[i] = '\0';
		ft_putendl(tmp);
		tab = ((tab[3] == '/') ? &tab[3] : '\0');
		*w = 1;
	}
	return (tmp);
}

void		change_pwd(char *tab, int home)
{
/*	char	*tmp;
	int		i;

	if (home == 0)
	{
		i= ft_strlen(tab);
		tab[i - 1] = ((tab[i - 1] == '/') ? '\0' : tab[i - 1]);
		tmp = find_value_envir(g_env, "PWD");
		tmp = simplify_pwd(tmp, tab, &i);
		tmp = ((i == 1) ? tmp : ft_strjoin(ft_strjoin(tmp, "/"), tab));
		tmp = ft_strjoin("setenv ", ft_strjoin("PWD ", tmp));
		tmp = ft_strjoin(tmp, "\0");
	}
	else
	{
		tmp = ft_strjoin("setenv ", "PWD ");
		tmp = ft_strjoin(tmp, find_value_envir(g_env, "HOME"));
	}
/*
** bug a cause du setenv, Ouais je vois sa!

	ft_setenv(ft_strsplit(tmp, ' '));
	free(tmp);*/
}

int			ft_cd(char **tab)
{
	if (!ft_strncmp("~", tab[1], 1) || !tab[1] || !ft_strcmp("$HOME", tab[1]))
	{
		ft_putendl("HOME");
		tab[1] = ft_strdup(find_value_envir("HOME"));
		if (chdir(tab[1]) == -1)
		{
			ft_putendl("error");
			return (-1);
		}
		change_pwd(tab[1], 1);
	}
	else if (chdir(tab[1]) == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	else
		change_pwd(tab[1], 0);
	return (0);
}
