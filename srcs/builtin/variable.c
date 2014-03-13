/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 12:47:27 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/13 08:51:59 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_var	*del_var(t_var *list, char *name)
{
	t_var	*tmp;

	if (!list)
		return (NULL);
	if (!ft_strcmp(list->name, name))
	{
		tmp = list->next;
		list = NULL;
		tmp = del_var(tmp, name);
	}
	else
		list->next = del_var(list->next, name);
	return (list);
}

t_var	*add_var(t_var *list, char *name, char *value)
{
	t_var	*tmp;
	t_var	*tmp2;

	tmp2 = list;
	tmp = (t_var *)ft_memalloc(sizeof(t_alias));
	tmp->name = name;
	tmp->value = value;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (list);
}

void	ft_set(char **tab)
{
	if (tab[1])
	{
		if (tab[2])
			set_var(tab[1], tab[2]);
		else
			ft_putendl("Missing one argument!");
	}
	else
	{
		print_list(g_env);
		if (g_var)
			show_var(g_var);
	}
}

void	set_var(char *name, char *value)
{
	if (find_value_envir(g_env, name))
	{
		ft_putstr("set: Tried to change the read-only variable: ");
		ft_putstr(name);
		ft_putendl(". (Use setenv for change environnement variable)");
		return ;
	}
	g_var = del_var(g_var, name);
	g_var = add_var(g_var, name, value);
}

void	unset_var(char *name)
{
	g_var = del_var(g_var, name);
}

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
