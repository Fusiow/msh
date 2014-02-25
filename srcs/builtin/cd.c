
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
		tab = ((tab[3] == '/') ? &tab[3] : '\0');
		*w = 1;
	}
	return (tmp);
}

void		change_pwd(int home)
{
	char	*tmp;
	char	*pwd[] = {"/bin/pwd", "-L", NULL};

	if (home == 0)
		tmp = result_cmd(pwd);
	else
		tmp = find_value_envir(g_env, "HOME");
	ft_setenv(g_env, "OLDPWD", find_value_envir(g_env, "PWD"));
	ft_setenv(g_env, "PWD", tmp);
}

int			ft_cd(char **tab)
{
	if (!tab[1])
	{
		ft_putendl(find_value_envir(g_env, "HOME"));
		tab[1] = find_value_envir(g_env, "HOME");
		if (chdir(tab[1]) == -1)
			return (cd_error(tab[1]));
		change_pwd(1);
	}
	else if (ft_strcmp("-", tab[1]) == 0)
	{
		chdir(find_value_envir(g_env, "OLDPWD"));
		ft_putendl(find_value_envir(g_env, "OLDPWD"));
		change_pwd(0);
	}
	else if (chdir(tab[1]) == -1)
			return (cd_error(tab[1]));
	else
		change_pwd(0);
	return (0);
}
