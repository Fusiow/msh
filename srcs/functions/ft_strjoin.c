/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:04:37 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/22 12:04:38 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	join = ft_strnew(len_s1 + len_s2 + 1);
	if (join == NULL)
		return (NULL);
	join = (char *) ft_memcpy(join, s1, len_s1);
	ft_memcpy(join + len_s1, s2, len_s2);
	return (join);
}
