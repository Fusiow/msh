/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/18 15:54:31 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			main(int ac, char **av, char **environ)
{
	char	*tmp;
	pid_t	child;
	int		rt;

	rt = 0;
	tmp = (char *)malloc(sizeof(char) * 150);
	ft_get_env(environ);
	if (ac != 1 && av)
		return (-1);
	while (1)
	{
		ft_putstr("Supah prompt $>");
		tmp = take_cmd();
		if (tmp && ft_exit(ft_strsplit(tmp, ' '), &rt) == -1)
			continue ;
		if (tmp && ft_exit(ft_strsplit(tmp, ' '), &rt) == 1)
			break ;
		child = fork();
		if (child)
			wait(0);
		else
			exec_cmd(ft_strsplit(tmp, ' '));
	}
	return (rt);
}
