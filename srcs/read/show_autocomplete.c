/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_autocomplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:47:45 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/23 14:26:59 by lsolofri         ###   ########.fr       */
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
	char	*description = NULL;

	i = 0;
	list = NULL;
	list = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"), ':'), list);
	if (list)
	{
		while (list)
		{
			++i;
			list = list->next;
		}
		if (i > 15)
			i = auto_comp_choice(i);
		list = NULL;
		list = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"), ':'), list);
		if (i != 1 && i != 0)
		{
			ft_putstr("\n");
			while (list)
			{
				aff_cmd(list->name, cmd);
				ft_putstr(GRAY);
				ft_putstr("\t\t\t\t\t(");
				description = get_cmd_description(list->name);
				if (description)
					ft_putstr(description);
				else
					ft_putstr("No Description");
				ft_putstr(")\n");
				ft_putstr(DEF);
				list = list->next;
			}
			return ("ok");
		}
		else if (i != 0)
		{
			i = 0;
			while (list->name[i] == cmd[i] && list->name[i] && cmd[i])
				++i;
			return (ft_strjoin(cmd, ft_strjoin(ft_strsub(list->name, i, ft_strlen(list->name)), " ")));
		}
	}
	ft_free(list);
	ft_free(description);
	return (NULL);
}

char	*make_cmd(char *str)
{
	int		i;

	i = 0;
	while (ft_isalpha(str[i]) && str[i])
		++i;
	return (ft_strsub(str, 0, i));
}

char	*show_autocomplete(char *str, int v)
{
	int				i;
	char			*tmp;
	static int		status;

	i = ft_strlen(str) - 1;
	if (v == 0)
		status = 0;
	else
	{
		while (str[i] != ' ' && i > 0)
			--i;
		if (i > 0)
			++i;
		tmp = ft_strsub(str, i, (ft_strlen(str) - i));
		if (status == 0)
		{
			status++;
			if (i == 0 && tmp[0] != '.' && tmp[0] != '/')
				tmp = show_tab(tmp);
			else if (tmp[0] == '-')
			{
				if (!tmp[1])
					show_diff_option(make_cmd(str));
			}
			else
				tmp = argument_completion(tmp, str);
		}
		else if (status == 1)
		{
			if (i == 0 && tmp[0] != '.' && tmp[0] != '/')
				tmp = spe_autocomp(str, ft_strlen(str), 0);
			else if (tmp[0] != '-')
				tmp = spe_argument_completion(tmp, str, 0);
		}
		if (tmp)
		{
			if (ft_strcmp(tmp, "ok") && tmp[0] != '-')
			{
				i = ft_strlen(tmp) - 1;
				while (i-- > ft_strlen(str))
					ft_putstr(tgetstr("nd", NULL));
				str = tmp;
			}
			else
			{
				if (tmp[0] == '-' && tmp[1])
					return (str);
					prompt();
					i = 0;
					while (i++ < ft_strlen(str))
						ft_putstr(" ");
			}
		}
	}
	return (str);
}
