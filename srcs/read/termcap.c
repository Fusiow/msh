/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:00:24 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/14 17:19:06 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	init_flag(struct termios *term)
{
	char	*name_term;

	name_term = getenv("TERM");
	if (!name_term)
		show_error_exit("No Environnement TERM variables");
	if (!tgetent(NULL, name_term))
		show_error_exit("System call: tgetent fail");
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
}

void	re_flag(struct termios *term)
{
	char	*name_term;

	name_term = getenv("TERM");
	if (!name_term)
		show_error_exit("No Environnement TERM variables");
	if (!tgetent(NULL, name_term))
		show_error_exit("System call: tgetent fail");
	tcgetattr(0, term);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
}

char	*init_buffer(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
	return (buffer);
}

char	*char_to_string(char c)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 1);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
