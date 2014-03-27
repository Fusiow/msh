/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 16:19:04 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static char	*isdollars(int *i, char *str)
{
	int		v;
	char	*tmp;
	char	*result;

	v = *i + 1;
	while (ft_isalpha(str[v]) && str[v])
		++v;
	result = search_var(g_var, ft_strsub(str, *i + 1, (v - *i - 1)));
	*i = v - 1;
	if (str[*i])
	{
		while (str[*i] != ' ' && str[*i])
			++*i;
		tmp = ft_strsub(str, v, (*i - v));
		result = ft_strjoin(result, tmp);
		ft_free(tmp);
	}
	return (result);
}

static char	*istild(int *i, char *str, int start)
{
	char	*tmp;
	char	*result;

	++*i;
	while (!(iswhite(str[*i])) && !(isop(str[*i])) && str[*i])
		++*i;
	tmp = ft_strsub(str, start + 1, (*i - start - 1));
	result = ft_strjoin(find_value_envir(g_env, "HOME"), tmp);
	return (result);
}

static char	*isbackquote(int *i, char *str)
{
	int		v;
	char	*tmp;
	char	*result;

	++*i;
	v = *i;
	while (str[*i] != '`' && str[*i])
		++*i;
	tmp = ft_strsub(str, v, (*i - v));
	result = result_cmd(tmp);
	return (result);
}

static char	*isbraquet(int *i, char *str)
{
	int		v;
	char	*result;

	v = *i + 1;
	while (str[*i] != ')' && str[*i])
		++*i;
	result = ft_strsub(str, v, (*i - v));
	return (result);
}

char		*ope_str(char *str, int start, int *i)
{
	char	*result;

	if (str[*i] == '$')
		result = isdollars(i, str);
	else if (str[*i] == '~')
		result = istild(i, str, start);
	else if (str[*i] == '`')
		result = isbackquote(i, str);
	else if (str[*i] == '(')
		result = isbraquet(i, str);
	else
		result = char_to_string(str[start]);
	return (result);
}
