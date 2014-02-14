/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:43:09 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/14 17:23:19 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*get_options(int fd)
{
	char	*str;

	while ((str = get_next_line(fd)))
	{
		if (ft_strncmp(str, ".Op Fl", 6) == 0)
			return (ft_strsub(str, 7, ft_strlen(str)));
	}
	return (NULL);
}

char	*read_description(int fd, char *c)
{
	char	*str;
	while ((str = get_next_line(fd)))
	{
		if (ft_strcmp(str, ft_strjoin(".It Fl ", c)) == 0)
			return (get_next_line(fd));
	}
	return (NULL);
}

t_option	*get_description(char *options, char *path)
{
	t_option	*list;

	list = NULL;
	if (options)
	{
		while (*options)
		{
			list = add_option(list, *options, read_description(open(path, O_RDONLY),
						char_to_string(*options)));
			options++;
		}
		return (list);
	}
	return (NULL);
}

t_option	*return_options(char *cmd)
{
	char		**path;
	char		*man_path;
	char		man[] = "man1/";

	path = ft_strsplit(get_man_path(), ':');
	while (*path)
	{
		man[3] = '1';
		while (man[3] != '9')
		{
			man_path = ft_strjoin(*path, ft_strjoin("/", ft_strjoin(man,
							ft_strjoin(cmd, ft_strjoin(".",
									char_to_string(man[3]))))));
			if (access(man_path, F_OK) != -1)
				return (get_description(get_options(open(man_path, O_RDONLY)),
							man_path));
			man[3]++;
		}
		path++;
	}
	return (NULL);
}