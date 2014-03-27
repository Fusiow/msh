/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:43:09 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 11:52:49 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char			*get_cmd_description(char *cmd)
{
	char		**path;
	char		*man_path;
	char		*man;
	char		*str;

	if ((path = ft_strsplit(find_value_envir(g_env, "MANPATH"), ':')))
	{
		man = ft_strdup("man1/");
		while (*path)
		{
			man[3] = '0';
			while (man[3]++ != '9')
			{
				man_path = make_man_path(*path, man, cmd);
				if (access(man_path, F_OK) != -1)
				{
					str = read_description_fd(man_path);
					if (str)
						return (str);
				}
			}
			path++;
		}
	}
	return (cmd);
}

char			*get_options(int fd)
{
	char		*str;

	str = NULL;
	while (get_next_line(fd, &str))
	{
		if (ft_strncmp(str, ".Op Fl", 6) == 0)
		{
			str = ft_strsub(str, 7, ft_strlen(str) - 7);
			break ;
		}
	}
	close(fd);
	return (str);
}

char			*read_description(int fd, char *c)
{
	char		*str;

	while (get_next_line(fd, &str))
	{
		if (ft_strcmp(str, ft_strjoin(".It Fl ", c)) == 0)
		{
			get_next_line(fd, &str);
			close(fd);
			return (ft_strdup(str));
		}
	}
	return (NULL);
}

t_option		*get_description(char *options, char *path)
{
	t_option	*list;

	list = NULL;
	if (options)
	{
		while (*options)
		{
			list = add_option(list, *options, read_description(open(path,
				O_RDONLY), char_to_string(*options)));
			options++;
		}
		return (list);
	}
	return (NULL);
}

t_option		*return_options(char *cmd)
{
	char		**path;
	char		*man_path;
	char		*man;

	man = ft_strdup("man1/");
	path = ft_strsplit(find_value_envir(g_env, "MANPATH"), ':');
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
