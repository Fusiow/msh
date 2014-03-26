/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 03:43:16 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/26 04:59:01 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/msh.h"

int		dquote_check(char *str, int *i)
{
	int		count;

	count = 1;
	++*i;
	while (str[*i] != '"' && str[*i])
	{
		if (str[*i] == '\\')
			++*i;
		++*i;
	}
	if (str[*i] == '"')
		count = 0;
	return (count);
}

int		squote_check(char *str, int *i)
{
	int		count;

	count = 1;
	++*i;
	while (str[*i] != '\'' && str[*i])
		++*i;
	if (str[*i] == '\'')
		count = 0;
	return (count);
}

int		bquote_check(char *str, int *i)
{
	int		count;

	count = 1;
	++*i;
	while (str[*i] != '`' && str[*i])
		++*i;
	if (str[*i] == '`')
		count = 0;
	return (count);
}

int		p_check(char *str, int *i)
{
	int		count;

	count = 1;
	++*i;
	while (iswhite(str[*i]))
		++*i;
	if (str[*i])
		count = 0;
	return (count);
}
