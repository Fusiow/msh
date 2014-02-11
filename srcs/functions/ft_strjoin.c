/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:07:41 by lsolofri          #+#    #+#             */
/*   Updated: 2013/12/30 14:47:04 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char const *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		v;

	i = 0;
	v = 0;
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
		ptr[v++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[v++] = s2[i++];
	ptr[v] = '\0';
	return (ptr);
}
