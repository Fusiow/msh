/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 23:52:29 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 23:52:39 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		main_options(char **av, int *choice)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp("-nocolor", av[i]))
			*choice = 1;
		else
		{
			ft_putstr("Unknown option: ");
			ft_putendl(av[i]);
		}
		++i;
	}
}

void		child(char **tab)
{
	signal(SIGTSTP, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	check_operators(tab, -1);
	check_redirection(tab);
	exec_cmd(tab);
}
