/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/23 19:15:48 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		iswhite(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int		isop(char c)
{
	char	optab[] = "$;^()=><`|&{}~"; 
	int		i;

	i = 0;
	while (optab[i])
	{
		if (c == optab[i])
			return (1);
		++i;
	}
	return (0);
}

int		iskey(char *str)
{
	char	*keyword[] = {"if", "do", "while", "in", "case", "done", "elif",
		"else", "esac", "fi", "for", "then", "until"};
	int		i;

	i = 0;
	while (ft_strcmp(keyword[i], str) != 0 && keyword[i])
		++i;
	if (keyword[i])
		return (1);
	return (0);
}

char	*spe_quote(char *str, int *i, char quote, int start)
{
	char	*result;
	char	*spe_result;
	int		j;

	while (str[*i] != ' ' && isop(str[*i]) && str[*i])
		++*i;
	result = ft_strsub(str, start, (ft_strlen(str) - start));
	ft_putendl(result);
	start = j = 0;
	spe_result = (char *)malloc(sizeof(char) * ft_strlen(result));
	while (result[start])
	{
		if (result[start] == quote && result[start - 1] != '\\')
			start++;
		if (result[start])
			spe_result[j] = result[start];
		start++;
		j++;
	}
	result[j] = '\0';
	return (spe_result);
}

char	*quote(char *str, int *i, char quote)
{
	char	*result;
	int		flag;
	int		j;
	char	*tmp;
	int		v;

	flag = j = 0;
	result = malloc(1024);
	++*i;
	while (flag == 0)
	{
		if (!str[*i])
			flag = 1;
		else if (str[*i] == quote && str[*i - 1] != '\\')
		{
			if (str[*i + 1] && str[*i + 1] == ' ')
				flag = 1;
			else if (!str[*i + 1])
				flag = 1;
			else
				++*i;
		}
		else if (str[*i] == '$' && str[*i - 1] != '\\')
		{
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
					result[j] = tmp[v];
					++j;
					++v;
				}
				result[j] = '\0';
			}
		}
		else
		{
			result[j] = str[*i];
			++j;
			++*i;
		}
	}
	result[j] = 0;
	++*i;
	return (result);
}

char	*ope_str(char *str, int start, int *i)
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
				free(tmp);
			}
	}
	else if (str[*i] == '~')
	{
		++*i;
		while (!(iswhite(str[*i])) && !(isop(str[*i])) && str[*i])
			++*i;
		tmp = ft_strsub(str, start + 1, (*i - start));
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

t_parse		*tokenize(char *str)
{
	t_parse		*list;
	int			len;
	int			i;
	int			start;
	int			openflag;

	openflag = 0;
	i = 0;
	list = NULL;
	if (check_line(str))
		return (list);
	while (str[i])
	{
		len = 0;
		while (iswhite(str[i]) && str[i])
			++i;
		start = i;
		if (isop(str[i]) == 1 && isop(str[i + 1]) == 1 && str[i] == str[i + 1])
		{
			len += 2;
			list = add_word(list, ft_strsub(str, start, len));
			i += 2;
		}
		else if (isop(str[i]))
		{
			len++;
			openflag = i;
			if (str[i] == '(')
				list = add_word(list, "(");
			if (ope_str(str, start, &i))
			{
				i = openflag;
				list = add_word(list, ope_str(str, start, &i));
			}
			if (str[i] == ')')
				list = add_word(list, ")");
			if (str[i])
				++i;
		}
		else if (str[i] == '\'' || str[i] == '"')
			list = add_word(list, quote(str, &i, str[i]));
		else
		{
			len = 0;
			while (iswhite(str[i]) == 0 && isop(str[i]) == 0 && str[i])
			{
				len++;
				++i;
			}
			list = add_word(list, ft_strsub(str, start, len));
		}
		while (iswhite(str[i]) && str[i])
			++i;
	}
	return (list);
}
