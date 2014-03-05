/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:40:27 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/03 18:32:00 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
size_t	ft_strlen(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		v;

	i = 0;
	v = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str)
	{
		while (s1[i])
			str[v++] = s1[i++];
		i = 0;
		while (s2[i])
			str[v++] = s2[i++];
		str[v] = '\0';
		return (str);
	}
	return (0);
}
