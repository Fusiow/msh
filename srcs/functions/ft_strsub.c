/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 12:05:17 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/22 12:05:23 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*ft_strsub(char const *s, t_ui start, size_t len)
{
	char	*sub;
	t_ui	i;

	i = 0;
	sub = ft_strnew(len + 1);
	if (sub == NULL)
		return (NULL);
	s += start;
	while (s[i] && len != 0)
	{
		sub[i] = s[i];
		i++;
		len--;
	}
	return (sub);
}
