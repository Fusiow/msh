
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/24 19:44:20 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		change_pwd(char *tab, int home)
{
	char	*tmp;
	int		i;

	i = 0;
	if (home == 0)
	{
		i= ft_strlen(tab);
		tab[i - 1] = ((tab[i - 1] == '/') ? '\0' : tab[i - 1]);
		tmp = find_value_envir("PWD");
		if (!ft_strncmp("..", tab, 2))
		{
			i = ft_strlen(tmp);
			while (tmp[i] != '/')
				i--;
			tmp[i] = '\0';
			i = 1;
		}
		tmp = ((i == 1) ? tmp : ft_strjoin(ft_strjoin(tmp, "/"), tab));
		tmp = ft_strjoin("setenv ", ft_strjoin("PWD ", tmp));
	}
	else
	{
		tmp = ft_strjoin("setenv ", "PWD ");
		tmp = ft_strjoin(tmp, find_value_envir("HOME"));
	}
	ft_setenv(ft_strsplit(tmp, ' '));
	free(tmp);
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
