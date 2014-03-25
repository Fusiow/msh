/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 12:47:27 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 16:43:59 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_var(t_var *list)
{
	while (list)
	{
		ft_putstr(list->name);
		ft_putstr("=");
		ft_putendl(list->value);
		list = list->next;
	}
}

char	*search_var(t_var *list, char *name)
{
	char	*result;

	result = find_value_envir(g_env, name);
	if (!result)
	{
		while (list && ft_strcmp(list->name, name))
			list = list->next;
		if (list)
			result = ft_strdup(list->value);
	}
	return (result);
}

void	export_var(t_var *list, char *name)
{
	while (list && ft_strcmp(list->name, name))
		list = list->next;
	if (list)
		g_env = ft_setenv(g_env, name, list->value);
	else
	{
		ft_putstr("Cannot find variable ");
		ft_putendl(name);
	}
}
