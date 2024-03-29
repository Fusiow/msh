/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 17:49:53 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 19:05:30 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			is_options(char *tmp, char *cmd, int i, int command)
{
	if (tmp)
	{
		if (!cmd[i] && check_prog(tmp))
			show_options_in_line(tmp);
		ft_free(tmp);
	}
	if (command == 0)
		command = 1;
	ft_putstr(DEF);
	return (command);
}

char		*print_command2(char *cmd, int *i)
{
	int		v;
	char	*tmp;

	v = *i;
	while (cmd[*i] != ' ' && cmd[*i])
		++*i;
	tmp = ft_strsub(cmd, v, (*i - v));
	if (check_prog(tmp) || !access(tmp, X_OK))
		ft_putstr(BLUE);
	else
		ft_putstr(RED);
	*i = v;
	return (tmp);
}

int			print_command(char *cmd, int *i, int command)
{
	int		v;
	char	*tmp;

	tmp = NULL;
	if (command == 0)
		tmp = print_command2(cmd, i);
	if (cmd[*i] == '-')
	{
		ft_putstr(SBLUE);
		v = -1;
	}
	while (cmd[*i] != ';' && cmd[*i] != '|' && cmd[*i] != ' ' && cmd[*i])
	{
		if (command == 1 && v != -1)
			ft_putstr(SBLUE2);
		ft_putchar(cmd[*i]);
		++*i;
	}
	return (is_options(tmp, cmd, *i, command));
}
