/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/23 20:15:18 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*escape_char(char *str)
{
	int		i;
	char	replace;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			flag = (flag ? 0 : 1);
		else if (str[i] == '"')
			flag = (flag ? 0 : 2);
		if (str[i] == '\\')
		{
			if (str[i + 1] == 'a')
				replace = '\a';
			else if (str[i + 1] == 'b')
				replace = '\b';
			else if (str[i + 1] == 'n')
				replace = '\n';
			else if (str[i + 1] == 't')
				replace = '\t';
			else if (str[i + 1] == 'v')
				replace = '\v';
			else if (str[i + 1] == 'f')
				replace = '\f';
			else if (str[i + 1] == 'r')
				replace = '\r';
			else if (str[i + 1] == 'e')
				replace = '\e';
			else
				replace = str[i + 1];
			++i;
			str = del_c(str, &i);
			if (replace != str[i] && flag)
			{
				++i;
				str = del_c(str, &i);
				str = change_cmd(i, ft_strdup(str), replace);
			}
			++i;
		}
		if (str[i])
			i++;
	}
	return (str);
}

int		check_line(char *str)
{
	t_error		err;
	int		i;

	i = err.dquote = err.squote = err.pipe = err.bquote = 0;
	while (str[i])
	{
		if (str[i] == '"' && str[i - 1] != '\\')
		{
			err.dquote = 1;
			++i;
			while (str[i] != '"' && str[i])
			{
				if (str[i] == '\\')
					++i;
				++i;
			}
			if (str[i] == '"')
				err.dquote = 0;
		}
		else if (str[i] == '\'' && str[i] != '\\')
		{
			err.squote = 1;
			++i;
			while (str[i] != '\'' && str[i])
				++i;
			if (str[i] == '\'')
				err.squote = 0;
		}
		else if (str[i] == '`' && str[i - 1] != '\\')
		{
			err.bquote = 1;
			++i;
			while (str[i] != '`' && str[i])
				++i;
			if (str[i] == '`')
				err.bquote = 0;
		}
		else if (str[i] == '|' && str[i - 1] != '\\')
		{
			err.pipe = 1;
			++i;
			while (iswhite(str[i]))
				++i;
			if (str[i])
				err.pipe = 0;
		}
		++i;
	}
	if (err.dquote == 1 || err.squote == 1 || err.squote == 1 ||
		err.pipe == 1 || err.bquote == 1)
		return (1);
	return (0);
}
