/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 06:57:02 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 10:48:37 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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

void	parser(char *cmd, int i, t_parse **list)
{
	int		v;

	while (cmd[i] == ' ' && cmd[i])
		++i;
	if (!cmd[i])
		return ;
	else if (cmd[i] == '"')
	{
		++i;
		v = i;
		while (cmd[i] != '"' && cmd[i])
			++i;
		*list = add_word(*list, ft_strsub(cmd, v, (i - v)));
	}
	else if (cmd[i] == '\'')
	{
		++i;
		v = i;
		while (cmd[i] != '\'' && cmd[i])
			++i;
		*list = add_word(*list, ft_strsub(cmd, v, (i - v)));
	}
	else if (cmd[i] == '>')
	{
		++i;
		if (cmd[i] == ' ')
		{
			while (cmd[i] == ' ' && cmd[i])
				++i;
		}
		v = i;
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			++i;
		*list = add_word(*list, ">");
		*list = add_word(*list, ft_strsub(cmd, v, (i - v)));
	}
	else if (cmd[i] == '<')
	{
		++i;
		if (cmd[i] == ' ')
		{
			while (cmd[i] == ' ' && cmd[i])
				++i;
		}
		v = i;
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			++i;
		*list = add_word(*list, "<");
		*list = add_word(*list, ft_strsub(cmd, v, (i - v)));

	}
	else if (cmd[i] == '|')
	{
		*list = add_word(*list, "|");
		++i;
	}
	else if (cmd[i] == ';')
	{
		*list = add_word(*list, ";");
		++i;
	}
	else
	{
		v = i;
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			++i;
		*list = add_word(*list, ft_strsub(cmd, v, (i - v)));
	}
	if (!cmd[i])
		return ;
	if (cmd[i] != ';' && cmd[i] != '|' && cmd[i - 1] != ';' && cmd[i - 1] != '|')
		++i;
	parser(cmd, i, list);
}

int		list_len_cmd(t_parse *list)
{
	int		i;

	i = 0;
	while (list != NULL && (ft_strcmp(list->str, ";")))
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

t_command	*quick_parse(char *str)
{
	t_parse 	*list;
	int			i;
	char		**tab;
	t_command	*result;

	i = 0;
	list = NULL;
	result = NULL;
	parser(str, 0, &list);
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
