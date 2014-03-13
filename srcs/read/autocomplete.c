/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 14:15:21 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/13 15:47:29 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"


void	show_complete(char *str, char *cmd)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	if (ft_strcmp(str, ""))
		ft_putstr(ft_strsub(str, ft_strlen(cmd), ft_strlen(str)));
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

void	show_options(char c)
{
	ft_putstr(GRAY);
	ft_putstr(tgetstr("sc", NULL));
	ft_putchar(c);
	ft_putstr(tgetstr("rc", NULL));
	ft_putstr(DEF);
}

void	show_options_in_line(char *cmd)
{
	char        **path;
	char        *man_path;
	char        man[] = "man1/";

	path = ft_strsplit(get_man_path(), ':');
	while (*path)
	{
		man[3] = '1';
		while (man[3] != '9')
		{
			man_path = ft_strjoin(*path, ft_strjoin("/", ft_strjoin(man,
							ft_strjoin(cmd, ft_strjoin(".",
									char_to_string2(man[3]))))));
			if (access(man_path, F_OK) != -1)
			{
				if (get_options(open(man_path, O_RDONLY)))
				{
					ft_putstr(tgetstr("sc", NULL));
					ft_putstr(GRAY);
					ft_putstr(" -");
					ft_putstr(get_options(open(man_path, O_RDONLY)));
					ft_putstr(DEF);
					ft_putstr(tgetstr("rc", NULL));	
				}
			}
			man[3]++;
		}
		path++;
	}
}
