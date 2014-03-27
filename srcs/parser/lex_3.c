/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 15:14:47 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char		*ope_str(char *str, int start, int *i)
{
	char	*result;
	char	*tmp;
	int		v;

	if (str[*i] == '$')
	{
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
	}
	else if (str[*i] == '~')
	{
		++*i;
		while (!(iswhite(str[*i])) && !(isop(str[*i])) && str[*i])
			++*i;
		tmp = ft_strsub(str, start + 1, (*i - start - 1));
		result = ft_strjoin(find_value_envir(g_env, "HOME"), tmp);
	}
	else if (str[*i] == '`')
	{
		++*i;
		v = *i;
		while (str[*i] != '`' && str[*i])
			++*i;
		tmp = ft_strsub(str, v, (*i - v));
		result = result_cmd(tmp);
	}
	else if (str[*i] == '(')
	{
		v = *i + 1;
		while (str[*i] != ')' && str[*i])
			++*i;
		result = ft_strsub(str, v, (*i - v));
	}
	else
		result = char_to_string(str[start]);
	return (result);
}
