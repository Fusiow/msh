/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 17:01:32 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		check_isop(char *str, int *i, int *start, t_parse *list)
{
	int		tmp;

	tmp = *i;
	if (str[*i] == '(')
	{
		while (str[*i] == '(')
			++*i;
		list = add_word(list, "(");
	}
	if (ope_str(str, *start, i))
	{
		*i = tmp;
		list = add_word(list, ope_str(str, *start, i));
	}
	if (str[*i] == ')')
		list = add_word(list, ")");
	if (str[*i])
		++*i;
}

void		check_word(char *str, int *i, int *start, t_parse **list)
{
	int		len;

	len = 0;
	while (iswhite(str[*i]) == 0 && isop(str[*i]) == 0 && str[*i])
	{
		len++;
		++*i;
	}
	*list = add_word(*list, ft_strsub(str, *start, len));
}

void		check_dredir(char *str, int *i, int *start, t_parse **list)
{
	int		len;

	len = 2;
	*list = add_word(*list, ft_strsub(str, *start, len));
	*i += 2;
}

t_parse		*tokenize(char *str)
{
	t_parse		*list;
	int			i;
	int			start;

	i = 0;
	list = NULL;
	while (str[i])
	{
		while (iswhite(str[i]) && str[i])
			++i;
		start = i;
		if (isop(str[i]) == 1 && isop(str[i + 1]) == 1 && str[i] == str[i + 1])
			check_dredir(str, &i, &start, &list);
		else if (isop(str[i]))
			check_isop(str, &i, &start, list);
		else if (str[i] == '\'' || str[i] == '"')
			list = add_word(list, quote(str, &i, str[i]));
		else
			check_word(str, &i, &start, &list);
		while (iswhite(str[i]) && str[i])
			++i;
	}
	return (list);
}
