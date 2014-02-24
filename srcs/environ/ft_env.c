/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:49:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/24 20:28:52 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		ft_setenv(char **av)
{
	char	**tmp;
	int		i;
	int		k;

	k = 0;
	if ((k = (ft_tabncmp(g_env, av))) == -1 && av[2])
	{
		i = (((tmp = ft_new_tab(ft_tablen(g_env) + 1)) != NULL) ? -1 : -1 );
		while (g_env[++i])
			tmp[i] = ft_strdup(g_env[i]);
		tmp[i] = ft_strdup(ft_strjoin(av[1], ft_strjoin("=", av[2])));
		ft_free_tab(g_env);
		i = (((g_env = ft_new_tab(ft_tablen(tmp))) != NULL) ? -1 : -1 );
		while (tmp[++i])
			g_env[i] = ft_strdup(tmp[i]);
		ft_free_tab(tmp);
	}
	else
		if (av[2])
			g_env[k] = ft_strdup(ft_strjoin(av[1], ft_strjoin("=", av[2])));
}

void		ft_unsetenv(char **av)
{
	int		k;


	k = ((ft_tabncmp(g_env, av) > -1) ? ft_tabncmp(g_env, av) : -1 );
	if (k > -1)
	{
		while (g_env[k])
		{
			if (g_env[k] && g_env[k + 1])
				g_env[k] = ft_strdup(g_env[k + 1]);
			else
				g_env[k] = NULL;
			k++;
		}
		g_env[k] = NULL;
	}
}

void		ft_print_env(void)
{
	int		i;

	i = -1;
	while (g_env[++i])
		ft_putendl(g_env[i]);
}

void		ft_get_env(char **environ)
{
	int		i;

	i = 0;
	while (environ[i])
		i++;
	if (i == 0)
		show_error_exit("Could not set environnement");
	g_env = ft_new_tab(i);
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		i++;
	}

}
