/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 15:14:27 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

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
