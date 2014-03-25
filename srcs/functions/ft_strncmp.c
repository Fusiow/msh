/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:40:50 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/25 18:58:11 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return ((int)s2[i]);
	if (s2 == NULL)
		return ((int)s1[i]);
	if (s1 != NULL && s2 != NULL)
	{
		while (i < n)
		{
			if (s1[i] != s2[i] && s1[i])
				return (((int)s1[i] - (int)s2[i]));
			i++;
		}
	}
	return (0);
}
