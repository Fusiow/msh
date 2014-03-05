/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 08:31:33 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/05 11:37:16 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	write_cmd(char *cmd, int i, int command)
{
	int			v;
	char		*tmp;

	tmp = NULL;
	while (cmd[i] && cmd[i] == ' ')
		ft_putchar(cmd[i++]);
	if (!cmd[i])
		return ;
	else if (cmd[i] == '"')
	{
		++i;
		v = i;
		while (cmd[i] != '"' && cmd[i])
			++i;
		if (cmd[i])
		{
			ft_putstr(YEL);
			++i;
		}
		else
			ft_putstr(RED);
		ft_putchar('"');
		write(1, &cmd[v], (i - v));
		ft_putstr(DEF);
	}
	else if (cmd[i] == '\'')
	{
		++i;
		v = i;
		while (cmd[i] != '\'' && cmd[i])
			++i;
		if (cmd[i])
		{
			ft_putstr(YEL);
			++i;
		}
		else
			ft_putstr(RED);
		ft_putchar('\'');
		write(1, &cmd[v], (i - v));
		ft_putstr(DEF);
	}
	else if (cmd[i] == '>')
	{
		ft_putstr(MAG);
		if (cmd[i + 1] == '>')
			ft_putchar(cmd[i++]);
		ft_putchar(cmd[i++]);
		ft_putstr(DEF);
		while (cmd[i] == ' ' && cmd[i])
			ft_putchar(cmd[i++]);
		v = i;
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			++i;
		ft_putstr(GRE);
		write(1, &cmd[v], (i - v));
		ft_putstr(DEF);
	}
	else if (cmd[i] == '<')
	{
		ft_putstr(MAG);
		if (cmd[i + 1] == '<')
			ft_putchar(cmd[i++]);
		ft_putchar(cmd[i++]);
		ft_putstr(DEF);
		while (cmd[i] == ' ' && cmd[i])
			ft_putchar(cmd[i++]);
		v = i;
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			++i;
		ft_putstr(GRE);
		write(1, &cmd[v], (i - v));
		ft_putstr(DEF);
	}
	else if (cmd[i] == '|' || cmd[i] == ';')
	{
		ft_putstr(MAG);
		ft_putchar(cmd[i++]);
		ft_putstr(DEF);
		command = 0;
	}
	else
	{
		if (command == 0)
		{
			command = 1;
			v = i;
			while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
				++i;
			tmp = ft_strsub(cmd, v, (i - v));
			if (check_prog(tmp))
				ft_putstr(BLUE);
			else
				ft_putstr(RED);
			i = v;
		}
		else
			ft_putstr(SBLUE);
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
			ft_putchar(cmd[i++]);
		if (tmp)
		{
			if (!cmd[i] && check_prog(tmp))
				show_options_in_line(tmp);
			free(tmp);
			tmp = NULL;
		}
		ft_putstr(DEF);
	}
	if (!cmd[i])
		return ;
	write_cmd(cmd, i, command);
}
