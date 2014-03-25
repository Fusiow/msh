/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 20:20:16 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 22:17:27 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_diff_option(char *str)
{
	t_option	*list;

	ft_putstr("\n");
	list = return_options(str);
	if (list)
	{
		while (list)
		{
			ft_putchar('-');
			ft_putchar(list->option);
			ft_putstr(GRAY);
			ft_putstr("\t\t(");
			if (list->description)
				ft_putstr(list->description);
			else
				ft_putstr("No Description");
			ft_putstr(")");
			ft_putendl(DEF);
			list = list->next;
		}
	}
	else
		ft_putstr("No Options!\n");
}
