/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 14:15:21 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 11:52:16 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void			show_complete(char *str, char *cmd)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	if (ft_strcmp(str, ""))
		ft_putstr(ft_strsub(str, ft_strlen(cmd), ft_strlen(str)));
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

void			show_options(char c)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	ft_putchar(c);
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

static void		show_the_options(char *man_path)
{
	char		*options;

	options = get_options(open(man_path, O_RDONLY));
	if (options)
	{
		ft_putstr(tgetstr("sc", NULL));
		ft_putstr(GRAY);
		ft_putstr(" -");
		ft_putstr(options);
		ft_putstr(DEF);
		ft_putstr(tgetstr("rc", NULL));
		ft_free(options);
	}
}

void			show_options_in_line(char *cmd)
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
			{
				if (get_options(open(man_path, O_RDONLY)))
					show_the_options(man_path);
			}
			man[3]++;
		}
		path++;
	}
}
