/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 20:20:16 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/15 20:32:43 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_diff_option(char *str)
{
	t_option	*list;

	ft_putstr("\n");
	list = return_options(str);
	while (list)
	{
		ft_putchar('-');
		ft_putchar(list->option);
		ft_putstr(GRAY);
		ft_putstr("\t\t(");
		ft_putstr(list->description);
		ft_putstr(")");
		ft_putendl(DEF);
		list = list->next;
	}
}
