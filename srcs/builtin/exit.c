/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 16:36:29 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		search_for_jobs(t_jobs *list)
{
	int		i;

	i = 0;
	while (list)
	{
		list = list->next;
		++i;
	}
	return (i);
}

void	kill_jobs(t_jobs *list)
{
	while (list)
	{
		kill(SIGTERM, list->pid);
		list = list->next;
	}
}

int				ft_exit(char **tab)
{
	int			i;
	int			rt;
	int			result;

	i = -1;
	rt = 0;
	result = 0;
	if (tab)
	{
		while (tab[1] && tab[1][++i] != '\0')
		{
			if (ft_isdigit(tab[1][i]))
				rt = ft_atoi(tab[1]);
			else
			{
				exit_error(tab);
				result = 1;
				break ;
			}
		}
	}
	if (!result)
		check_exit_status(rt);
	return (0);
}

void		check_exit_status(int rt)
{
	char	*ret;

	if (search_for_jobs(g_jobs))
	{
		ft_putstr("You have unfinished jobs. Exit anyway? (y/n)");
		ret = take_cmd(1);
	}
	if (!ft_strcmp("y", ret))
	{
		kill_jobs(g_jobs);
		ft_gc(NULL, E_GCFREEGC);
		ft_putendl("Goodbye!");
		_exit(rt);
	}
}
