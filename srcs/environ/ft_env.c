/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:49:25 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/12 16:53:55 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		ft_setenv(char **av)
{
	char	**tmp;
	int		i;

	i = ft_tablen(g_env);;
	tmp = ft_new_tab(i + 1);
	i = 0;
	while (g_env[i])
	{
		tmp[i] = ft_strdup(g_env[i]);
		i++;
	}
	tmp[i] = ft_strdup(ft_strjoin(av[2], ft_strjoin("=", av[3])));
	i = ft_tablen(tmp);
	ft_free_tab(g_env);
	g_env = ft_new_tab(i);
	i = 0;
	while (tmp[i])
	{
		g_env[i] = ft_strdup(tmp[i]);
		i++;
	}
	ft_free_tab(tmp);
}

/*void		ft_unsetenv(void)
{

}
*/
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

	i = 0;
	ft_get_env(environ);
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
				ft_setenv(av);
		}
	}
	ft_print_env();
	return (0);
}
