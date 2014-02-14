/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 14:15:21 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/14 16:02:50 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
t_option	*return_options(char *cmd);


void	show_complete(char *str, char *cmd)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	if (ft_strcmp(str, ""))
		ft_putstr(ft_strsub(str, ft_strlen(cmd), ft_strlen(str)));
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

void	show_options(char c)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	ft_putchar(c);
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

void	show_rest(char *str, char *cmd)
{
	int		i;
	t_option	*list;

	i = 1;
	if (str[i] == '-')
	{
		if (!str[i + 1])
		{
			list = return_options(cmd);
			ft_putstr(str);
			if (list)
				show_options(list->option);
		}
		else
			ft_putstr(str);
	}
	else
		ft_putstr(str);
}