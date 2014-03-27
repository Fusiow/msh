/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 19:54:06 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 14:26:15 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	no_conf_msg(void)
{
	ft_putendl("Welcome in MSH!");
	ft_putstr("You have no configuration file for the moment, ");
	ft_putendl("please, make a choice! :");
	ft_putendl("[0] Create an empty configuration file");
	ft_putendl("[1] Create a default configuration file");
	ft_putendl("Other for do nothing");
}

void	no_conf(void)
{
	struct termios	term;
	char			*buffer;
	int				fd;

	init_flag(&term);
	buffer = (char *)ft_memalloc(sizeof(char) * 3);
	ft_putstr(tgetstr("cl", NULL));
	no_conf_msg();
	read(0, buffer, 3);
	if (buffer[0] == '0')
		open(ft_strjoin(find_value_envir(g_env, "HOME"),
						"/.mshrc"), O_CREAT, 0777);
	else if (buffer[0] == '1')
	{
		fd = open(ft_strjoin(find_value_envir(g_env, "HOME"),
							"/.mshrc"), O_WRONLY | O_CREAT, 0777);
		write(fd, "alias l \"ls\"\nalias ll \"ls -la\"\n", 32);
		close(fd);
	}
	ft_putstr(tgetstr("cl", NULL));
	re_flag(&term);
}
