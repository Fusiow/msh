/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:02:08 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/28 16:16:10 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (len == 0 || !s)
		return (0);
	ptr = (char *)malloc((sizeof(char)) * len);
	if (ptr != NULL)
	{
		while (i < len)
		{
			ptr[i] = s[start];
			++start;
			++i;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
