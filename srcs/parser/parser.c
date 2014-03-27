/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 06:57:02 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 16:41:57 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_parse				*add_word(t_parse *list, char *str)
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

t_command			*add_tab(t_command *result, char **tab)
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

char				*check_line_cmd(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' && str[i])
		++i;
	if (!str[i])
		return (NULL);
	i = 0;
	if (check_line(str) == 2 || check_redir(str) == 1)
	{
		ft_putendl("msh: Parse error");
		return (NULL);
	}
	while (check_line(str) == 1 || str[ft_strlen(str) - 1] == '\\')
	{
		ft_putstr("parse> ");
		str = ft_strjoin(str, take_cmd(1));
	}
	if (check_line(str) == 2 || check_redir(str) == 1)
	{
		ft_putendl("msh: Parse error");
		return (NULL);
	}
	return (str);
}

t_command			*tab_contain(t_parse *list, int i)
{
	char		**tab;
	glob_t		globlist;
	t_command	*result;
	int			j;

	result = NULL;
	while (list)
	{
		i = 0;
		tab = (char **)ft_memalloc(sizeof(char *) * 1024);
		while (list != NULL && (ft_strcmp(list->str, ";")) && i < 1024)
		{
			j = -1;
			glob(list->str, GLOB_NOCHECK, 0, &globlist);
			while (globlist.gl_pathv[++j])
				tab[i++] = ft_strdup(globlist.gl_pathv[j]);
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

t_command			*quick_parse(char *str)
{
	t_parse		*list;

	if (!(str = check_line_cmd(str)))
		return (NULL);
	str = escape_char(str);
	list = tokenize(str);
	return (tab_contain(list, 0));
}
