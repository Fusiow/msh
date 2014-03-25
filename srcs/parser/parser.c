/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 06:57:02 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/26 05:44:37 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
#include <stdio.h>

t_parse		*add_word(t_parse *list, char *str)
{
	t_parse		*tmp;
	t_parse		*tmp2;

	tmp2 = list;
	tmp = (t_parse *)ft_memalloc(sizeof(t_parse));
	tmp->str = str;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (list);
}

int		list_len_cmd(t_parse *list)
{
	int		i;

	i = 0;
	while (list && (ft_strcmp(list->str, ";")))
	{
		list = list->next;
		++i;
	}
	return (i);
}

t_command	*add_tab(t_command *result, char **tab)
{
	t_command	*tmp;
	t_command	*tmp2;

	tmp2 = result;
	tmp = (t_command *)ft_memalloc(sizeof(t_command));
	tmp->cmd = tab;
	tmp->next = NULL;
	if (result == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (result);
}

void	show_me_the_truth_bitch_get_outta_my_way(t_parse *list)
{
	while (list)
	{
		printf("%s\n", list->str);
		list = list->next;
	}
}

t_command	*quick_parse(char *str)
{
	t_parse 	*list;
	int			i;
	char		**tab;
	t_command	*result;
	glob_t		globlist;
	int			j;

	i = 0;
	result = NULL;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			j = 1;
		++i;
	}
	if (!j)
		return (result);
	i = 0;
	if (check_line(str) == 2 || check_redir(str) == 1)
	{
		ft_putendl("msh: Parse error.");
		return (result);
	}
	while (check_line(str) == 1 || str[ft_strlen(str) - 1] == '\\')
	{
		ft_putstr("> ");
		str = ft_strjoin(str, take_cmd(1));
	}
	if (check_line(str) == 2)
	{
		ft_putendl("msh: Parse error.");
		return (result);
	}
	str = escape_char(str);
	list = tokenize(str);
//	show_me_the_truth_bitch_get_outta_my_way(list);
	result = NULL;
	while (list)
	{
		i = list_len_cmd(list);
		tab = (char **)ft_memalloc(sizeof(char *) * 1024);
		tab[i] = NULL;
		i = 0;
		while (list != NULL && (ft_strcmp(list->str, ";")) && i < 1024)
		{
			j = 0;
			glob(list->str, GLOB_NOCHECK, 0, &globlist);
			while (globlist.gl_pathv[j])
			{
				tab[i] = ft_strdup(globlist.gl_pathv[j]);
				++i;
				++j;
			}
			globfree(&globlist);
			list = list->next;
		}
		tab[i] = NULL;
		result = add_tab(result, tab);
		if (list)
			list = list->next;
	}
	return (result);
}
