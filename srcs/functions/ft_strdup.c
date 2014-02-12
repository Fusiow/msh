/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:49:25 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/12 16:56:41 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(ft_strlen(s));
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
