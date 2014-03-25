/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 12:24:55 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 18:19:29 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			search_for_jobs(t_jobs *list)
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

void		kill_jobs(t_jobs *list)
{
	while (list)
	{
		kill(SIGTERM, list->pid);
		list = list->next;
	}
}

int			ft_exit(char **tab)
{
	int		i;
	int		rt;
	int		result;

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
				result = exit_error(tab);
				break ;
			}
		}
	}
	if (!result && check_exit_status())
		_exit(rt);
	return (0);
}

int			check_exit_status(void)
{
	char	*ret;

	ret = NULL;
	if (search_for_jobs(g_jobs))
	{
		ft_putstr("You have unfinished jobs. Exit anyway? (y/n)");
		ret = take_cmd(1);
	}
	if (ret)
	{
		if (!ft_strcmp("y", ret))
		{
			ft_putendl("Goodbye!");
			kill_jobs(g_jobs);
			ft_gc(NULL, E_GCFREEGC);
			return (1);
		}
	}
	else
	{
		ft_putendl("Goodbye!");
		return (1);
	}
	return (0);
}
