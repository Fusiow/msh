
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/24 18:53:04 by aardjoun         ###   ########.fr       */
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
		while (tab[i] != '\0')
			i++;
		if (tab[i - 1] == '/')
			tab[i - 1] = '\0';
		ft_putendl("GNA");
		tmp = ft_strjoin(ft_strjoin(find_value_envir("PWD"), "/"), tab);
		tmp = ft_strjoin("setenv ", ft_strjoin("PWD ", tmp));
		ft_setenv(ft_strsplit(tmp, ' '));
	}
	else
	{
		tmp = ft_strjoin("setenv ", "PWD ");
		tmp = ft_strjoin(tmp, find_value_envir("HOME"));
		ft_setenv(ft_strsplit(tmp, ' '));
	}
	free(tmp);
}

int			ft_cd(char **tab)
{
	if (!ft_strncmp("~", tab[1], 1) || tab[1] == NULL || !ft_strcmp("$HOME", tab[1]))
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
