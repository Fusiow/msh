/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:54:36 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/12 16:38:58 by lsolofri         ###   ########.fr       */
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
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>

/*
** ERRORS
*/
void	show_error(char *str);
void	show_error_exit(char *str);

/*
** READ
*/
char	*read_cmd(void);
void	init_flag(struct termios *term);
void	re_flag(struct termios *term);
char	*init_buffer(char *buffer);
char	*history(int choice, char *str);

/*
** FUNCTIONS
*/
int		ft_putchar(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
char	**ft_new_tab(int i);
void	ft_free_tab(char **tab);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isprint(int c);
void	ft_putendl(char const *s);
void	ft_putnbr(int nb);
void	ft_putstr(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** ENVIRON FT_ENV.C
*/

void	ft_get_env(char **environ);
void	ft_print_env(void);
void	ft_setenv(char **av);
void	ft_unsetenv(void);

#endif /* MSH_H */
