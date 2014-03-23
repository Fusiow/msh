/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 04:12:42 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/22 12:20:46 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_alias	*del_alias(t_alias *list, char *name)
{
	t_alias	*tmp;

	if (!list)
		return (NULL);
	if (!ft_strcmp(list->alias, name))
	{
		tmp = list->next;
		ft_free(list);
		tmp = del_alias(tmp, name);
		return (tmp);
	}
	else
	{
		list->next = del_alias(list->next, name);
		return (list);
	}
}

t_alias	*add_alias(t_alias *list, char *alias, char *value)
{
	t_alias	*tmp;
	t_alias	*tmp2;

	tmp2 = list;
	tmp = (t_alias *)ft_memalloc(sizeof(t_alias));
	tmp->alias = alias;
	tmp->value = value;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (list);
}

char	**is_alias(t_alias *list, char **tab)
{
	t_command	*result;

	while (list)
	{
		if (ft_strcmp(tab[0], list->alias) == 0)
		{
			result = quick_parse(list->value);
			tab = ft_insert_tab(tab, result->cmd, 0);
		}
		list = list->next;
	}
	return (tab);
}

void	show_alias(t_alias *list)
{
	while (list)
	{
		ft_putstr(list->alias);
		ft_putstr("='");
		ft_putstr(list->value);
		ft_putendl("'");
		list = list->next;
	}
}

void	ft_alias(char **tab)
{
	if (tab[1] && tab[2])
	{
		g_alias = del_alias(g_alias, tab[1]);
		g_alias = add_alias(g_alias, tab[1], tab[2]);
	}
	else
		show_alias(g_alias);
}
