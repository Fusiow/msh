/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:17:53 by rkharif           #+#    #+#             */
/*   Updated: 2014/02/28 17:39:42 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static int	countchar(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	countword(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	nb = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		len = countchar(s + i, c);
		if (len)
		{
			nb++;
			i += len;
		}
		else
			i++;
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	char				**ret;
	unsigned int		i;
	unsigned int		nbword;
	unsigned int		nbchr;

	i = 0;
	nbword = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * (countword(s, c) + 1))))
	ret[countword(s, c)] = NULL;
	if (s == 0)
		return (0);
	while (s[i])
	{
		nbchr = countchar(s + i, c);
			if (nbchr)
			{
				ret[nbword] = ft_strsub(s, i, nbchr);
				ret[nbword][nbchr] = '\0';
				nbword++;
				i += nbchr;
			}
			else
				i++;
	}
	ret[nbword] = NULL;
	return (ret);
}
