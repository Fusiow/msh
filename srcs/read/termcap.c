/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:00:24 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/11 15:34:18 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	init_flag(struct termios *term)
{
	char	*term;

	term = getenv("TERM");
	if (!term)
		show_error_exit("No Environnement TERM variables");
	if (!tgetent(NULL, term))
		show_error_exit("System call: tgetent fail");
	if (!tcgetattr(0, term))
		show_error_exit("System call: tcgetattr fail");
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 258;
	term->c_cc[VTIME] = 0;
	if (!tcsetattr(0, 0, term))
		show_error_exit("System call: tcsetattr fail");
}

void	re_flag(struct termios *term)
{
	char	*term;

	name = getenv("TERM");
	if (!term)
		show_error_exit("No Environnement TERM variables");
	if (!tgetent(NULL, term))
		show_error_exit("System call: tgetent fail");
	if (!tcgetattr(0, term))
		show_error_exit("System call: tcgetattr fail");
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	if (!tcsetattr(0, 0, term))
		show_error_exit("System call: tcsetattr fail");
}

char	*init_buffer(char *buffer)
{
	buffer[0] = '\0';
	buffer[1] = '\0';
	buffer[2] = '\0';
	buffer[3] = '\0';
}
