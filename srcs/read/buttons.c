/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:24:20 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/12 16:08:33 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		a_right(int i, int len)
{
	if (i < len)
	{
		ft_putstr(tgetstr("nd", NULL));
		++i;
	}
	return (i);
}

int		a_left(int i, int len)
{
	if (i > 0)
	{
		ft_putstr(tgetstr("le", NULL));
		--i;
	}
	return (i);
}

void	clear_line(int i, int v)
{
	while (i > 1)
	{
		ft_putstr(tgetstr("le", NULL));
		--i;
	}
	ft_putstr(tgetstr("ce", NULL));
}

void	replace_cursor(int i, int v)
{
	while (v > i)
	{
		ft_putstr(tgetstr("le", NULL));
		--v;
	}
}

int		arrow(int i, char key, int len, char **result)
{
	if (key == 65)
	{
		clear_line(i + 1, ft_strlen(*result));
		*result = history(1, NULL);
		i = ft_strlen(*result) + 1;
		ft_putstr(*result);	
	}
	else if (key == 66)
	{
		clear_line(i + 1, ft_strlen(*result));
		*result = history(2, NULL);	
		i = ft_strlen(*result) + 1;
		ft_putstr(*result);	
	}
	else if (key == 67)
		i = a_right(i, len);
	else if (key == 68)
		i = a_left(i, len);
	return (i);
}
