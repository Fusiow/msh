/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:18:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/12 15:46:03 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*history(int choice, char *str)
{
	static char		*s_history[500];
	static int		i = 0;

	if (choice == 0)
	{
		while (s_history[i])
			++i;
		s_history[i] = ft_strdup(str);
		s_history[i + 1] = NULL;
	}
	else if (choice == 1)
	{
		if (i > 0)
			return (s_history[i--]);
	}
	else if (choice == 2)
	{
		if (s_history[i + 1])
			return (s_history[i++]);
	}
	if (choice == 0)
	{
		int v = 0;
		while (s_history[v])
			ft_putendl(s_history[v++]);
		ft_putnbr(i);
	}
	return (s_history[i]);
}
