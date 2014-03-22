/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:04:20 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/22 12:04:23 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *) s1;
	str2 = (char *) s2;
	i = 0;
	while (n != 0)
	{
		str1[i] = str2[i];
		n--;
		i++;
	}
	return (str1);
}
