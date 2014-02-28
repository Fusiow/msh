/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 04:12:42 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/27 10:28:22 by lsolofri         ###   ########.fr       */
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
		free(list);
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
	tmp = (t_alias *)malloc(sizeof(t_alias));
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

char	*is_alias(t_alias *list, char *alias)
{
	while (list && ft_strcmp(list->alias, alias))
		list = list->next;
	if (list)
		return (list->value);
	return (NULL);
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
		if (is_alias(g_alias, tab[1]))
			g_alias = del_alias(g_alias, tab[1]);
		g_alias = add_alias(g_alias, tab[1], tab[2]);
	}
	else
		show_alias(g_alias);
}
