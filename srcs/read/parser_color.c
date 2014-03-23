/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 08:31:33 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/23 20:51:53 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	print_quote(char *cmd)
{
	int		j;

	j = 0;
	while (cmd[j])
	{
		if (cmd[j] == '\\')
		{
			ft_putstr(RED2);
			ft_putchar(cmd[j++]);
			if (cmd[j])
				ft_putchar(cmd[j]);
			ft_putstr(YEL);
		}
		else if (cmd[j] == '$')
		{
			ft_putstr(GRE2);
			ft_putchar(cmd[j++]);
			while (ft_isalpha(cmd[j]) && cmd[j])
				ft_putchar(cmd[j++]);
			--j;
			ft_putstr(YEL);
		}
		else
			ft_putchar(cmd[j]);
		++j;
	}
}

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
		{
			if (cmd[i] == '\\')
				++i;
			++i;
		}
		if (cmd[i])
		{
			ft_putstr(YEL);
			++i;
			ft_putchar('"');
			print_quote(ft_strsub(cmd, v, (i - v)));
		}
		else
		{
			ft_putstr(RED);
			ft_putchar('"');
			while (v < i)
				ft_putchar(cmd[v++]);
		}
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
	else if (cmd[i] == '|' || cmd[i] == ';' || cmd[i] == '&' || cmd[i] == '(' || cmd[i] == ')')
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
			v = i;
			while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i] != '(' && cmd[i] != ')' && cmd[i])
				++i;
			tmp = ft_strsub(cmd, v, (i - v));
			if (check_prog(tmp))
				ft_putstr(BLUE);
			else
				ft_putstr(RED);
			i = v;
		}
		if (cmd[i] == '-')
		{
			ft_putstr(SBLUE);
			v = -1;
		}
		while (cmd[i] != ' ' && cmd[i] != ';' && cmd[i] != '|' && cmd[i])
		{
			if (command == 1 && v != -1)
				ft_putstr(SBLUE2);
			ft_putchar(cmd[i++]);
		}
		if (tmp)
		{
			if (!cmd[i] && check_prog(tmp))
				show_options_in_line(tmp);
			ft_free(tmp);
		}
		if (command == 0)
			command = 1;
		ft_putstr(DEF);
	}
	if (!cmd[i])
		return ;
	write_cmd(cmd, i, command);
}
