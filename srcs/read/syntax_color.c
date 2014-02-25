/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:04:42 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 15:09:13 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_list	*add_type(t_list *list, char *str, char *type)
{
	t_list	*tmp;
	t_list	*temp;

	temp = list;
	tmp = malloc(sizeof(t_list));
	tmp->name = ft_strdup(str);
	if (type)
		tmp->type = ft_strdup(type);
	else
		tmp->type = NULL;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = tmp;
	}
	return (list);
}

t_list	*recup_prog(char *str, char **tab, t_list *list)
{
	int		i;
	DIR		*rep;
	struct dirent	*show;

	i = 0;
	if (ft_strncmp(str, "exit", ft_strlen(str)) == 0)
				list = add_type(list, "exit", "Builtin");
	else if (ft_strncmp(str, "setenv", ft_strlen(str)) == 0)
				list = add_type(list, "setenv", "Builtin");
	else if (ft_strncmp(str, "unsetenv", ft_strlen(str)) == 0)
				list = add_type(list, "unsetenv", "Builtin");
	else if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
				list = add_type(list, "cd", "Builtin");
	else if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
				list = add_type(list, "env", "Builtin");
	while (tab[i])
	{
		rep = opendir(tab[i++]);
		while ((show = readdir(rep)))
		{
			if (ft_strncmp(str, show->d_name, ft_strlen(str)) == 0)
				list = add_type(list, show->d_name, "Executable");
		}
		closedir(rep);
	}
	return (list);
}

void	show_cmd(char *str)
{
	int		i;
	char	*cmd;
	t_list	*list;
	char	*name;
	char	*rest;

	i = 0;
	list = NULL;
	name = NULL;
	rest = NULL;
	while (str[i] != ' ' && str[i])	
		++i;
	if (i != 0)
	{
		cmd = ft_strsub(str, 0, i);
		list = recup_prog(cmd, ft_strsplit(getenv("PATH"), ':'), list);
		if (list)
			name = list->name;
		while (list)
		{
			if (ft_strcmp(cmd, list->name) == 0)
			{
				ft_putstr(BLUE);
				break ;
			}
			list = list->next;
		}
		if (!list)
			ft_putstr(RED);
		ft_putstr(cmd);
		ft_putstr(DEF);
		if ((ft_strlen(str) - i) != 0)
			rest = ft_strsub(str, i, ft_strlen(str) - 1);
		if (list && !rest)
			show_options_in_line(cmd);
		if (!list && name && !rest)
			show_complete(name, cmd);
		if (rest)
			show_rest(rest, cmd);
		free(list);
		free(cmd);
		free(name);
	}
}
