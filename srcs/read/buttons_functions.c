/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 20:02:47 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 20:27:08 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			distrib_arrow(int i, char **result, char *buffer, int *v)
{
	if (*result)
		i = arrow(i, buffer[2], ft_strlen(*result), result);
	else
		i = arrow(i, buffer[2], 0, result);
	if (buffer[2] != 65 && buffer[2] != 66)
		*v = 1;
	return (i);
}

int			distrib_tab(int i, char **result)
{
	char	*tmp;

	tmp = ft_strdup(*result);
	*result = show_autocomplete(*result, 1);
	if (ft_strcmp(*result, tmp))
		i = ft_strlen(*result);
	else
	{
		*result = tmp;
		ft_putstr(tgetstr("le", NULL));
		i = ft_strlen(tmp);
	}
	return (i);
}

void		clear_and_prompt(void)
{
	ft_putstr(tgetstr("cl", NULL));
	prompt();
}

int			ctrl_a(int i, char **result)
{
	if (i != 0)
	{
		i = 0;
		replace_cursor(i, ft_strlen(*result));
	}
	return (i);
}

int			ctrl_k(int i, char **result)
{
	while (i + 1 < ft_strlen(*result))
	{
		ft_putstr(" ");
		++i;
	}
	i = ft_strlen(*result);
	return (i);
}
