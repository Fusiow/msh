/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 13:10:28 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/27 15:10:54 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int				iswhite(char c)
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

int				isop(char c)
{
	static char	optab[] = "$;^()><`|&{}~";
	int			i;

	i = 0;
	while (optab[i])
	{
		if (c == optab[i])
			return (1);
		++i;
	}
	return (0);
}

char			*spe_quote(char *str, int *i, char quote, int start)
{
	char		*result;
	char		*spe_result;
	int			j;

	while (str[*i] != ' ' && isop(str[*i]) && str[*i] != ';' && str[*i])
		++*i;
	result = ft_strsub(str, start, (ft_strlen(str) - start));
	ft_putendl(result);
	start = 0;
	j = 0;
	spe_result = (char *)ft_memalloc(sizeof(char) * ft_strlen(result));
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
