/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:05:41 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 03:01:48 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		read_get_next_line(int fd, int *i, int *nbread, char *buff)
{
	if (*i == *nbread)
	{
		*i = 0;
		if (!(*nbread = read(fd, buff, GNL_LEN)))
			return (1);
	}
	return (0);
}

int		eol_get_next_line(int fd, int *i, int *nbread, char *buff)
{
	while (buff[*i] && buff[*i] != '\n')
	{
		(*i)++;
		if (read_get_next_line(fd, i, nbread, buff))
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		buff[GNL_LEN];
	static int		i = 0;
	static int		nbread = 0;
	int				n;
	char			*str;

	n = 0;
	str = NULL;
	if (read_get_next_line(fd, &i, &nbread, buff))
		return (0);
	str = malloc(sizeof(char) * GNL_LEN);
	while (buff[i] && buff[i] != '\n' && n < GNL_LEN)
	{
		str[n++] = buff[i++];
		if (read_get_next_line(fd, &i, &nbread, buff))
			return (str);
	}
	if (n == GNL_LEN)
		if (eol_get_next_line(fd, &i, &nbread, buff))
			return (str);
	i++;
	return (str);
}
