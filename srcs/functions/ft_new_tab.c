/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:01:34 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/13 08:58:42 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	**ft_new_tab(int i)
{
	char	**tab;
	int		n;

	n = 0;
	tab = (char **)ft_memalloc((i + 1) * sizeof(char *));
	while (n <= i)
		tab[n++] = NULL;
	return (tab);
}
