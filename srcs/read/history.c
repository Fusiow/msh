/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:18:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:59:23 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void				add_history(char *str)
{
	int				i;
	int				res;

	i = 0;
	res = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] != ' ')
				res = 1;
			++i;
		}
		if (res)
			history(0, str);
	}
}

static char			*choice_one(char *s_history, int *i, char *result)
{
	if (*i >= 0)
	{
		result = s_history;
		if (*i > 0)
			--*i;
	}
	return (result);
}

static char			*choice_two(char *s_history, int *i, char *result,
		char *next)
{
	if (next)
	{
		if (*i == 0)
		{
			++*i;
			result = next;
		}
		else
			result = s_history;
		++*i;
	}
	else
		result = NULL;
	return (result);
}

char				*history(int choice, char *str)
{
	static char		*s_history[500];
	static int		i = 0;
	static char		*result;

	if (choice == 0)
	{
		while (s_history[i])
			++i;
		s_history[i] = ft_strdup(str);
		s_history[i + 1] = NULL;
	}
	else if (choice == 1)
		result = choice_one(s_history[i], &i, result);
	else if (choice == 2)
		result = choice_two(s_history[i], &i, result, s_history[i + 1]);
	return (result);
}
