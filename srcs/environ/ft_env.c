/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:49:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/11 17:31:28 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		ft_setenv(void)
{
	char	**tmp;
	int		i;

	i = 0;
	while (env[i])
		i++;
	tmp = ft_new_tab(i + 1);
	while (g_env[++i])
		tmp[i] = ft_strdup(g_env[i]);
	tmp[i + 1] = ft_strdup(ft_strjoin(av[2], ft_strjoin("=", av[3])));
	i = 0;
	while (tmp[i])
		i++;
	g_env = ft_new_tab(i);
	i = -1;
	while (tmp[++i])
		g_env[i] = ft_strdup(tmp[i]);
	tmp = ft_free_tab(tmp);
}

void		ft_unsetenv(void)
{

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



int			main(int ac, char **av, char **environ)
{
	int i;
	int s;

	i = 0;
	s = 0;
	if (ac > 2)
	{
		if (ft_strcmp("unsetenv", av[1]) == 0)
		{
			while (ft_strncmp(g_env[i], av[2], ft_strlen(av[2])) != 0)
				i++;
			free(g_env[i]);
			i = 0;
		}
		if (ac > 3)
		{
			if (ft_strcmp("setenv", av[1]) == 0)
				s = 1;
		}
		g_env = ft_get_env(environ, s, av);
	}
	return (0);
}
