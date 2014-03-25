/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_man_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 19:21:45 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 19:52:35 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*make_man_path(char *path, char *man, char *cmd)
{
	return (ft_strjoin(path, ft_strjoin("/", ft_strjoin(man, ft_strjoin(cmd,
	ft_strjoin(".", char_to_string(man[3])))))));
}

char	*read_description_fd(char *man_path)
{
	int		fd;
	char	*str;
	char	*result;

	result = NULL;
	fd = open(man_path, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &str))
		{
			if (ft_strcmp(ft_strsub(str, 0, 3), ".Nd") == 0)
			{
				close(fd);
				result = ft_strsub(str, 4, ft_strlen(str) - 4);
				break ;
			}
		}
		close(fd);
	}
	return (result);
}
