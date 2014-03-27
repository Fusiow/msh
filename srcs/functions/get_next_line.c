/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 18:47:54 by mfaye             #+#    #+#             */
/*   Updated: 2014/03/27 13:25:27 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void		malloc_more(char **buf, int size)
{
	int		i;
	char	*tmp;

	tmp = *buf;
	*buf = ft_memalloc(sizeof(char) * (ft_strlen(tmp) + size + 1));
	i = -1;
	while (tmp[++i] != '\0')
		(*buf)[i] = tmp[i];
	(*buf)[i] = '\0';
	ft_free(tmp);
}

static int		get_part(char **buf, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *buf;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] != '\n')
		return (0);
	tmp[i] = '\0';
	*line = ft_strdup(*buf);
	*buf = ft_strdup(*buf + i + 1);
	ft_free(tmp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buf = NULL;
	int				ret;
	int				i;

	i = 0;
	if (buf == NULL)
		buf = ft_strdup("");
	if (get_part(&buf, line))
		return (1);
	i = ft_strlen(buf);
	malloc_more(&buf, BUF_SIZE);
	ret = read(fd, buf + i, BUF_SIZE);
	if (ret == -1)
		return (-1);
	buf[i + ret] = '\0';
	if (ret != 0)
		return (get_next_line(fd, line));
	if (*buf == '\0')
		return (0);
	*line = ft_strdup(buf);
	buf = ft_strdup(buf + i + ret);
	return (1);
}
