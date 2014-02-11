/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:49:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/11 16:01:22 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../..0/includes/msh.h"
#include <stdlib.h>
#include <stdio.h>

char **g_env;

char		**ft_get_env(char **environ, int s, char **av)
{
	int		i;

	i = 0;
	while (environ[i])
		i++;
	if (i == 0)
	{
		printf("42sh: Could not set up terminal\n");
		exit(0);
	}
	g_env = ft_new_tab(i + s);
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		i++;
	}
	if (s == 1)
		g_env[i] = ft_strdup(ft_strjoin(av[2], ft_strjoin("=", av[3])));
	return (g_env);
}



int			main(__attribute__ ((unused)) int ac, char **av, char **environ)
{
	int i;
	int s;

	i = 0;
	s = 0;
	if (ft_strcmp("setenv", av[1]) == 0 && ac > 3)
		s = 1;
	g_env = ft_get_env(environ, s, av);
	while (g_env[i])
	{
		printf("%s\n", g_env[i]);
		i++;
	}
	return (0);
}
