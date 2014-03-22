/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 06:57:02 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/22 05:29:52 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"
#include <stdio.h>

t_parse		*add_word(t_parse *list, char *str)
{
	t_parse		*tmp;
	t_parse		*tmp2;

	tmp2 = list;
	tmp = (t_parse *)malloc(sizeof(t_parse));
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
	tmp = (t_command *)malloc(sizeof(t_command));
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

	i = 0;
	str = escape_char(str);
	list = tokenize(str);
//	show_me_the_truth_bitch_get_outta_my_way(list);
	result = NULL;
	while (list)
	{
		i = list_len_cmd(list);
		tab = (char **)malloc(sizeof(char *) * i + 1);
		i = 0;
		while (list != NULL && (ft_strcmp(list->str, ";")))
		{
			tab[i] = list->str;
			++i;
			list = list->next;
		}
		tab[i] = NULL;
		result = add_tab(result, tab);
		if (list)
			list = list->next;
	}
	return (result);
}
