/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:19:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 15:57:31 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		change_pwd(int home)
{
	char	*tmp;

	if (home == 0)
		tmp = getcwd(NULL, 1064);
	else
		tmp = find_value_envir(g_env, "HOME");
	ft_setenv(g_env, "OLDPWD", find_value_envir(g_env, "PWD"));
	if (!tmp)
		tmp = ft_strdup("/");
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
