/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:49:25 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/13 08:59:57 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)ft_memalloc(ft_strlen((char *)s) + 1);
	if (!result)
		return (0);
	while (s[i] != '\0')
	{
		result[i] = s[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}
