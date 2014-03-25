/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 17:24:15 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:23:54 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		quote_it(char *cmd, int i)
{
	int		v;

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
		print_quote(ft_strsub(cmd, v, (i - v)), 0);
	}
	else
	{
		ft_putstr(RED);
		ft_putchar('"');
		write(1, &cmd[v], (i - v));
	}
	ft_putstr(DEF);
	return (i);
}

int		quote_it2(char *cmd, int i)
{
	int		v;

	v = i;
	while (cmd[i] != '\'' && cmd[i])
	{
		if (cmd[i] == '\\')
			++i;
		++i;
	}
	if (cmd[i])
	{
		ft_putstr(YEL);
		++i;
		ft_putchar('\'');
		print_quote(ft_strsub(cmd, v, (i - v)), 0);
	}
	else
	{
		ft_putstr(RED);
		ft_putchar('\'');
		write(1, &cmd[v], (i - v));
	}
	ft_putstr(DEF);
	return (i);
}

int		redirection_right(char *cmd, int i)
{
	int		v;

	ft_putstr(MAG);
	if (cmd[i + 1] == '>')
		ft_putchar(cmd[i++]);
	ft_putchar(cmd[i++]);
	ft_putstr(DEF);
	while (cmd[i] == ' ' && cmd[i])
		ft_putchar(cmd[i++]);
	v = i;
	while ((ft_isalpha(cmd[i])) && cmd[i])
		++i;
	ft_putstr(GRE);
	write(1, &cmd[v], (i - v));
	ft_putstr(DEF);
	return (i);
}

int		redirection_left(char *cmd, int i)
{
	int		v;

	ft_putstr(MAG);
	if (cmd[i + 1] == '<')
		ft_putchar(cmd[i++]);
	ft_putchar(cmd[i++]);
	ft_putstr(DEF);
	while (cmd[i] == ' ' && cmd[i])
		ft_putchar(cmd[i++]);
	v = i;
	while ((ft_isalpha(cmd[i])) && cmd[i])
		++i;
	ft_putstr(GRE);
	write(1, &cmd[v], (i - v));
	ft_putstr(DEF);
	return (i);
}

int		new_command(int i, char *cmd)
{
	ft_putstr(MAG);
	ft_putchar(cmd[i]);
	ft_putstr(DEF);
	return (0);
}
