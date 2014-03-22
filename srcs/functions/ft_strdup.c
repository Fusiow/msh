/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:04:47 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/22 12:04:49 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		size;

	size = ft_strlen((char *)s1);
	if ((dup = (char *) ft_memalloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
