/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 11:34:17 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/12 14:31:47 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*del_c(char *result, int *i)
{
	int		tmp;

	if (*i != 0)
	{
		if (*i != 1)
			ft_putstr(tgetstr("le", NULL));
		ft_putstr(tgetstr("le", NULL));
		--*i;
		tmp = *i;
		while (result[*i + 1])
			result[*i] = result[++*i];
		result[*i] = '\0';
		*i = tmp;
	}
	return (result);
}