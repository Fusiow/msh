/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 11:34:17 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/23 12:55:26 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*del_c(char *result, int *i)
{
	int		tmp;

	if (*i != 0)
	{
		show_autocomplete(NULL, 0);
		spe_argument_completion(NULL, NULL, 1);
		spe_autocomp(NULL, 0, 1);
		if (*i != 1)
			ft_putstr(tgetstr("le", NULL));
		ft_putstr(tgetstr("le", NULL));
		--*i;
		tmp = *i;
		while (result[*i + 1])
		{
			result[*i] = result[*i + 1];
			++*i;
		}
		result[*i] = '\0';
		*i = tmp;
		if (*i == 0)
			result[0] = 0;
	}
	return (result);
}
