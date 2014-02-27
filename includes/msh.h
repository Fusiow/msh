/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:54:36 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/27 09:45:06 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

/*
 ** GLOBAL LIST
 */

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env	*g_env;
/*
 ** DEFINES
 */

# define GRAY "\033[1;30m"
# define RED "\033[1;31m"
# define GRE "\033[1;32m"
# define YEL "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAG "\033[1;35m"
# define SBLUE "\033[1;36m"
# define DEF "\033[0m"

# define GNL_LEN 1024

/*
 ** INCLUDE OF LIBS
 */

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>

// !!!!!!!!!!!!!!!!!!!!!
# include <string.h>

/*
 ** LIST FOR AUTOCOMP
 */

typedef struct		s_struct
{
	char			*name;
	char			*type;
	struct s_struct	*next;
}					t_list;

typedef struct		s_option
{
	char			option;
	char			*description;
	struct s_option	*next;
}					t_option;

/*
 ** ALIASES
 */

typedef struct		s_alias
{
	char			*alias;
	char			*value;
	struct s_alias	*next;
}					t_alias;

t_alias	*g_alias;

/*
 ** PARSER
 */

typedef struct		s_parse
{
	char			*str;
	struct s_parse	*next;
}					t_parse;

typedef struct			s_command
{
	char				**cmd;
	struct s_command	*next;
}						t_command;

t_command	*quick_parse(char *str);

/*
 ** ERRORS
 */

void		show_error(char *str);
void		show_error_exit(char *str);
void		exit_error(char **tab);
void		unknow_cmd(char *str);
int			cd_error(char *str);

/*
 ** READ
 */

char		*read_cmd(void);
void		init_flag(struct termios *term);
void		re_flag(struct termios *term);
char		*init_buffer(char *buffer);
char		*history(int choice, char *str);
char		*char_to_string(char c);
char		*del_c(char *result, int *i);
void		show_complete(char *str, char *cmd);
void		show_options(char c);
void		show_rest(char *str, char *cmd);
int			a_right(int i, int len);
int			a_left(int i, int len);
void		clear_line(int i, int v);
void		replace_cursor(int i, int v);
int			arrow(int i, char key, int len, char **result);
char		*get_options(int fd);
char		*read_description(int fd, char *c);
t_option	*get_description(char *options, char *path);
t_option	*return_options(char *cmd);
char		*change_cmd(int i, char *result, char letter);
int			distrib_buttons(int i, char **result, char *buffer, int *v);
char		*take_cmd(void);
t_list		*add_type(t_list *list, char *str, char *type);
t_list		*recup_prog(char *str, char **tab, t_list *list);
void		show_cmd(char *str);
t_option	*add_option(t_option *list, char option, char *description);
char		*get_cmd_description(char *cmd);
char		*show_autocomplete(char *str);
void		show_options_in_line(char *cmd);
void		show_diff_option(char *str);
void		syntax_color_rest(char *str);
void		write_cmd(char *str, int i, int command);
int			check_prog(char *str);

/*
 ** FUNCTIONS
 */

int			ft_putchar(char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_strlen(char *s);
char		**ft_new_tab(int i);
void		ft_free_tab(char **tab);
int			ft_tablen(char **tab);
int			ft_tabncmp(char **env, char **av);
char		*ft_strdup(const char *s1);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isprint(int c);
void		ft_putendl(char const *s);
void		ft_putnbr(int nb);
void		ft_putstr(char const *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(char *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		*get_man_path(void);
int			ft_isdigit(char c);
int			ft_atoi(const char *str);
char		*result_cmd(char **tab);

/*
 ** ENVIRON
 */
t_env	*add_env(t_env *env, char *name, char *value);
void	new_env(char **env);
void	print_list(t_env *env);
char	*find_value_envir(t_env *env, char *str);
t_env	*ft_unsetenv(t_env *env, char *str);
t_env	*ft_setenv(t_env *env, char *name, char *value);
char	**make_env_tab(t_env *env);

/*
 ** BUILTIN
 */

void		ft_echo(char **tab);
int			ft_exit(char **tab, int *rt);
int			ft_cd(char **tab);
void		load_conf_file(void);
char		*is_alias(t_alias *list, char *alias);
void		ft_alias(char **tab);

/*
 ** MAIN
 */

void		ft_mishell(char *line);
char		**ft_get_path(char **env, char *line);
void		exec_cmd(char **tab);
int			detect_built(int *rt, char **tab, int *bc);
void		pre_exec(char *str, int *rt, int *ret);

/*
 ** PROMPT
 */
void	basic_prompt(void);
void	prompt(void);
void	prompt_interpreter(char *str);

/*
 ** PIPE
 */
int	check_redirection(char **tab);
void	infile(char *str);
char	**re_tab(char **tab, int i);
void	outfile(char *str);
void	spe_outfile(char *str);
void	go_pipe(char	**tab);
t_command *split_pipe(t_command *list);
char	**join_tab(char **tab);

#endif /* MSH_H */
