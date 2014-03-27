/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 16:59:28 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*replace_esc_char(char *str, char replace, int flag, int *i)
{
	replace = 0;
	if (str[*i + 1] == 'a')
		replace = '\a';
	else if (str[*i + 1] == 'b')
		replace = '\b';
	else if (str[*i + 1] == 'n')
		replace = '\n';
	else if (str[*i + 1] == 't')
		replace = '\t';
	else if (str[*i + 1] == 'v')
		replace = '\v';
	else if (str[*i + 1] == 'f')
		replace = '\f';
	else if (str[*i + 1] == 'r')
		replace = '\r';
	if (replace && flag)
	{
		++*i;
		str = del_c(str, i);
		++*i;
		str = del_c(str, i);
		str = change_cmd(*i, ft_strdup(str), replace);
	}
	return (str);
}

char	*escape_char(char *str)
{
	int		i;
	char	replace;
	int		flag;

	i = 0;
	flag = 0;
	replace = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			flag = (flag ? 0 : 1);
		else if (str[i] == '"')
			flag = (flag ? 0 : 2);
		if (str[i] == '\\')
			str = replace_esc_char(str, replace, flag, &i);
		++i;
	}
	if (str[i])
		i++;
	return (str);
}

void	err_init(t_error *err)
{
	err->dquote = 0;
	err->squote = 0;
	err->bquote = 0;
	err->pipe = 0;
	err->par = 0;
	err->redir = 0;
}

int		check_par(char *str, int *i)
{
	int		opar;
	int		cpar;

	opar = 0;
	cpar = 0;
	while (str[*i])
	{
		if (str[*i] == '(')
			opar++;
		if (str[*i] == ')')
			cpar++;
		++*i;
	}
	if (opar > cpar)
		return (1);
	else if (cpar > opar)
		return (2);
	else
		return (0);
}

int		check_line(char *str)
{
	t_error		err;
	int			i;

	err_init(&err);
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && str[i - 1] != '\\')
			err.dquote = dquote_check(str, &i);
		else if (str[i] == '\'' && str[i] != '\\')
			err.squote = squote_check(str, &i);
		else if (str[i] == '`' && str[i - 1] != '\\')
			err.bquote = bquote_check(str, &i);
		else if (str[i] == '|' && str[i - 1] != '\\')
			err.pipe = p_check(str, &i);
		else if (str[i] == '(' || str[i] == ')')
			err.par = check_par(str, &i);
		++i;
	}
	if (err.par == 2 || err.redir == 2)
		return (2);
	if (err.dquote == 1 || err.squote == 1 || err.pipe == 1
			|| err.bquote == 1 || err.par == 1)
		return (1);
	return (0);
}
