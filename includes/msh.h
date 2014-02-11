/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:54:36 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/11 15:05:09 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

/*
** GLOBAL VARIABLE
*/

char	**g_env;

/*
** INCLUDE OF LIBS
*/
# include <unistd.h>
# include <stdlib.h.h>
# include <termios.h>
# include <termcap.h>

/*
** ERRORS
*/
void	show_error(char *str);

/*
** READ
*/
char	*read_cmd(void);
void	init_flag(struct termios *term);
#endif /* MSH_H */
