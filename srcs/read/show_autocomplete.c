/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_autocomplete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:47:45 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 22:16:07 by lsolofri         ###   ########.fr       */
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

char	*aff_prog_list(t_list *list, char *cmd)
{
	char	*description;

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

char	*show_tab(char *cmd)
{
	t_list	*li;
	int		i;

	i = 0;
	li = NULL;
	li = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"), ':'), li);
	if (li)
	{
		i = list_prog_len(li);
		if (i > 15)
			i = auto_comp_choice(i);
		if (i != 1 && i != 0)
			return (aff_prog_list(li, cmd));
		else if (i != 0)
		{
			i = 0;
			while (li->name[i] == cmd[i] && li->name[i] && cmd[i])
				++i;
			return (ft_strjoin(cmd, ft_strjoin(ft_strsub(li->name, i,
			ft_strlen(li->name)), " ")));
		}
	}
	ft_free(li);
	return (NULL);
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
			tmp = status_equal_zero(tmp, str, i, status++);
		else if (status == 1)
			tmp = status_equal_one(tmp, str, i);
		if (tmp)
			str = show_command_complete(tmp, i, str);
	}
	return (str);
}
