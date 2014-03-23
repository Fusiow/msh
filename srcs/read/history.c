/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:18:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/26 22:11:50 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	add_history(char *str)
{
	int		i;
	int		res;

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

char	*history(int choice, char *str)
{
	static char		*s_history[500];
	static int		i = 0;
	static char		*result;
	int				v;

	if (choice == 0)
	{
		while (s_history[i])
			++i;
		s_history[i] = ft_strdup(str);
		s_history[i + 1] = NULL;
	}
	else if (choice == 1)
	{
		if (i >= 0)
		{
			result = s_history[i];
			if (i > 0)
				--i;
		}
	}
	else if (choice == 2)
	{
		if (s_history[i + 1])
		{
			if (i == 0)
				++i;
			result = s_history[i];
			++i;
		}
		else
			result = NULL;
	}
	else if (choice == 3)
	{
		v = 0;
		while (s_history[v + 5])
			++v;
		while (s_history[v])
		{
			ft_putnbr(v);
			ft_putchar('\t');
			ft_putendl(s_history[v++]);
		}
	}
	return (result);
}
