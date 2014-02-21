/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_autocomplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:47:45 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 16:11:14 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	aff_cmd(char *str, char *cmd)
{
	int		i;

	i = 0;
	ft_putstr(BLUE);
	while (str[i] == cmd[i] && str[i] && cmd[i])
		ft_putchar(str[i++]);
	ft_putstr(DEF);
	while (str[i])
		ft_putchar(str[i++]);
}

char	*show_tab(char *cmd)
{
	t_list	*list;
	int		i;

	i = 0;
	list = NULL;
	list = recup_prog(cmd, ft_strsplit(getenv("PATH"), ':'), list);
	if (list)
	{
		while (list)
		{
			++i;
			list = list->next;
		}
		list = NULL;
		list = recup_prog(cmd, ft_strsplit(getenv("PATH"), ':'), list);
		if (i != 1)
		{
			ft_putstr("\n");
			while (list)
			{
				aff_cmd(list->name, cmd);
				ft_putstr(GRAY);
				ft_putstr("\t\t\t\t\t(");
				if (list->type)
					ft_putstr(list->type);
				else
					ft_putstr("No Description");
				ft_putstr(")\n");
				ft_putstr(DEF);
				list = list->next;
			}
			return ("ok");
		}
		else
		{
			i = 0;
			while (list->name[i] == cmd[i] && list->name[i] && cmd[i])
				++i;
			return (ft_strjoin(cmd, ft_strsub(list->name, i, ft_strlen(list->name))));
		}
	}
	return (NULL);
}

char	*show_autocomplete(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != ' ' && str[i])
		++i;
	if (!str[i])
	{
		tmp = show_tab(ft_strsub(str, 0, i));
		if (tmp && ft_strcmp(tmp, "ok"))
		{
			i = ft_strlen(tmp) - 1;
			while (i > ft_strlen(str))
			{
				ft_putstr(tgetstr("nd", NULL));
				--i;
			}
			str = tmp;
		}
		else if (tmp && ft_strcmp("ok", tmp) == 0)
		{
			prompt();
			ft_putstr(" ");
			if (i != 1)
				ft_putstr(tgetstr("nd", NULL));
			if (i == 3)
			{
				ft_putstr(tgetstr("nd", NULL));
			}
			else if (i > 3)
			{
				ft_putstr(tgetstr("nd", NULL));
				ft_putstr(tgetstr("nd", NULL));
			}
		}
	}
	else if (str[i + 1] == '-' && !str[i + 2])
	{
		show_diff_option(ft_strsub(str, 0, i));
		prompt();
		ft_putstr("    ");
		if (i == 1)
				ft_putstr(tgetstr("le", NULL));
			else if (i == 3)
				ft_putstr(tgetstr("nd", NULL));
			else if (i > 3)
			{
				ft_putstr(tgetstr("nd", NULL));
				ft_putstr(tgetstr("nd", NULL));
			}
	}
	return (str);
}
