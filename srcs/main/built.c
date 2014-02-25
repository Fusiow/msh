/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 18:56:49 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 01:54:46 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		detect_built(int *rt, char **tab, int *bc)
{
	int		ret;

	if (!(ret = ft_strcmp("exit", tab[0])))
		*bc = ft_exit(tab, rt);
//	else if (!(ret = ft_strcmp("cd", tab[0])))
//		ft_cd(tab);
	else if (!(ret = ft_strcmp("env", tab[0])))
		print_list(g_env);
	else if (!(ret = ft_strcmp("setenv", tab[0])))
		g_env = ft_setenv(g_env, tab[1], tab[2]);
	else if (!(ret = ft_strcmp("unsetenv", tab[0])))
		g_env = ft_unsetenv(g_env, tab[1]);
	else if (!(ret = ft_strcmp("echo", tab[0])))
		ft_echo(tab);
	return (ret);
}
