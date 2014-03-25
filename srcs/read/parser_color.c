/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 08:31:33 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:27:09 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	print_quote(char *cmd, int j)
{
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
	while (cmd[i] && cmd[i] == ' ')
		ft_putchar(cmd[i++]);
	if (!cmd[i])
		return ;
	else if (cmd[i] == '"')
		i = quote_it(cmd, ++i);
	else if (cmd[i] == '\'')
		i = quote_it2(cmd, ++i);
	else if (cmd[i] == '>')
		i = redirection_right(cmd, i);
	else if (cmd[i] == '<')
		i = redirection_left(cmd, i);
	else if (cmd[i] == '|' || cmd[i] == ';' || cmd[i] == '&'
			|| cmd[i] == '(' || cmd[i] == ')')
		command = new_command(i++, cmd);
	else
		command = print_command(cmd, &i, command);
	if (!cmd[i])
		return ;
	write_cmd(cmd, i, command);
}
