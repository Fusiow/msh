/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 17:12:54 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char		*isdollar_backslash(char *str, char *result, int *i, int *j)
{
	char	*tmp;
	int		v;

	v = *i + 1;
	while (ft_isalpha(str[v]))
		++v;
	tmp = search_var(g_var, ft_strsub(str, *i + 1, (v - *i - 1)));
	*i = v;
	v = 0;
	if (tmp)
	{
		while (tmp[v])
		{
			result[*j] = tmp[v];
			++*j;
			++v;
		}
		result[*j] = '\0';
	}
	return (result);
}

int			isquote_backslash(char *str, int *i)
{
	int		flag;

	flag = 0;
	if (str[*i + 1] && !ft_isalpha(str[*i + 1]))
		flag = 1;
	else if (!str[*i + 1])
		flag = 1;
	else
		++*i;
	return (flag);
}

char		*quote(char *str, int *i, char quote)
{
	char	*result;
	int		flag;
	int		j;

	flag = 0;
	j = 0;
	result = ft_memalloc(1024);
	++*i;
	while (flag == 0)
	{
		if (!str[*i])
			flag = 1;
		else if (str[*i] == quote && str[*i - 1] != '\\')
			flag = isquote_backslash(str, i);
		else if (str[*i] == '$' && str[*i - 1] != '\\')
			result = isdollar_backslash(str, result, i, &j);
		else
		{
			result[j++] = str[*i];
			++*i;
		}
	}
	result[j] = 0;
	++*i;
	return (result);
}
