/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:54:36 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 15:33:57 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H

/*
** DEFINES
*/

# define GC_NBSTART 100
# define GRAY "\033[1;30m"
# define GRAY2 "\033[0;30m"
# define RED "\033[1;31m"
# define RED2 "\033[0;31m"
# define GRE "\033[1;32m"
# define GRE2 "\033[0;32m"
# define YEL "\033[1;33m"
# define BLUE "\033[1;34m"
# define BLUE2 "\033[0;34m"
# define MAG "\033[1;35m"
# define SBLUE "\033[1;36m"
# define SBLUE2 "\e[4;36m"
# define DEF "\033[0m"

# define BUF_SIZE 1024

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
# include <signal.h>
# include <glob.h>

/*
** GLOBAL LIST
*/

typedef struct			s_env
{
	char				*name;
	char				*value;
	int					protect;
	struct s_env		*next;
}						t_env;

t_env					*g_env;

typedef unsigned int	t_ui;

/*
** LIST FOR VARIABLES
*/

typedef struct			s_var
{
	char				*name;
	char				*value;
	struct s_var		*next;
}						t_var;

t_var					*g_var;
char					*search_var(t_var *list, char *name);

/*
** LIST FOR JOBS CONTROL
*/

typedef struct			s_jobs
{
	char				*name;
	int					job;
	int					pid;
	int					status;
	struct s_jobs		*next;
}						t_jobs;

t_jobs					*g_jobs;

/*
** LIST FOR AUTOCOMP
*/

typedef struct			s_struct
{
	char				*name;
	char				*type;
	struct s_struct		*next;
}						t_list;

typedef struct			s_option
{
	char				option;
	char				*description;
	struct s_option		*next;
}						t_option;

/*
** ALIASES
*/

typedef struct			s_alias
{
	char				*alias;
	char				*value;
	struct s_alias		*next;
}						t_alias;

t_alias					*g_alias;

/*
** PARSER
*/

typedef struct			s_parse
{
	char				*str;
	struct s_parse		*next;
}						t_parse;

typedef struct			s_command
{
	char				**cmd;
	struct s_command	*next;
}						t_command;

t_command				*quick_parse(char *str);
t_parse					*add_word(t_parse *list, char *str);
t_parse					*tokenize(char *str);
int						iswhite(char c);
char					*escape_char(char *str);
int						check_line(char *str);
int						dquote_check(char *str, int *i);
int						squote_check(char *str, int *i);
int						bquote_check(char *str, int *i);
int						p_check(char *str, int *i);
int						check_redir(char *str);
int						isop(char c);
char					*ope_str(char *str, int start, int *i);
char					*quote(char *str, int *i, char quote);

/*
** LEAKS
*/

typedef struct s_gc		t_gc;
typedef struct s_gcinfo	t_gcinfo;

struct					s_gcinfo
{
	int					nb;
	int					size;
	t_gc				*first_avail;
	t_gc				*first;
};

typedef enum			e_gcop
{
	E_GCADD,
	E_GCFREE,
	E_GCFREEALL,
	E_GCFREEGC
}						t_gcop;

struct					s_gc
{
	void				*p;
	t_gc				*next;
};

/*
** ERRORS
*/
typedef struct			s_error
{
	int					dquote;
	int					squote;
	int					pipe;
	int					bquote;
	int					par;
	int					redir;
}						t_error;

void					show_error(char *str);
void					show_error_exit(char *str);
int						exit_error(char **tab);
void					unknow_cmd(char *str);
int						cd_error(char *str);
void					err_no_file(char *str);
void					pid_error(char *tab);
void					job_error(int k);

/*
** READ
*/

char					*read_cmd(void);
void					init_flag(struct termios *term);
void					re_flag(struct termios *term);
char					*init_buffer(char *buffer);
char					*history(int choice, char *str);
void					add_history(char *str);
char					*char_to_string(char c);
char					*char_to_string2(char c);
char					*del_c(char *result, int *i);
void					show_complete(char *str, char *cmd);
void					show_options(char c);
void					show_rest(char *str, char *cmd);
int						a_right(int i, int len);
int						a_left(int i, int len);
void					clear_line(int i, int v);
void					replace_cursor(int i, int v);
int						arrow(int i, char key, int len, char **result);
char					*get_options(int fd);
char					*read_description(int fd, char *c);
t_option				*get_description(char *options, char *path);
t_option				*return_options(char *cmd);
char					*change_cmd(int i, char *result, char letter);
int						distrib_buttons(int i, char **res, char *buf, int *v);
char					*take_cmd(int choice);
t_list					*add_type(t_list *list, char *str, char *type);
t_list					*recup_prog(char *str, char **tab, t_list *list);
void					show_cmd(char *str);
t_option				*add_option(t_option *list, char option, char *desc);
char					*get_cmd_description(char *cmd);
char					*show_autocomplete(char *str, int v);
void					show_options_in_line(char *cmd);
void					show_diff_option(char *str);
void					syntax_color_rest(char *str);
void					write_cmd(char *str, int i, int command);
int						check_prog(char *str);
int						auto_comp_choice(int i);
char					*spe_autocomp(char *cmd, int len, int x);
char					*argument_completion(char *str, char *cmd);
void					aff_cmd(char *str, char *cmd);
char					*spe_argument_completion(char *cmd, char *str, int x);
int						up_arrow(char **result, int i);
void					print_quote(char *str, int j);
int						quote_it(char *cmd, int i);
int						quote_it2(char *cmd, int i);
int						redirection_left(char *cmd, int i);
int						redirection_right(char *cmd, int i);
int						new_command(int i, char *cmd);
int						print_command(char *cmd, int *i, int command);
char					*make_man_path(char *path, char *man, char *cmd);
char					*read_description_fd(char *man_path);
char					*i_equal_len(char *c, char *result);
char					*i_equal_zero(char *c, char *result);
char					*insert_a_char(char *result, char *c, int i);
int						distrib_arrow(int i, char **result, char *buf, int *v);
int						distrib_tab(int i, char **result);
void					clear_and_prompt(void);
int						ctrl_a(int i, char **result);
int						ctrl_k(int i, char **result);
char					*make_cmd(char *str);
int						list_prog_len(t_list *list);
char					*status_equal_zero(char *tmp, char *str, int i, int st);
char					*status_equal_one(char *tmp, char *str, int i);
char					*show_command_complete(char *tmp, int i, char *str);
char					*show_tab(char *cmd);

/*
** FUNCTIONS
*/

int						ft_putchar(char c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strsub(char const *s, unsigned int sta, size_t len);
char					**ft_new_tab(int i);
void					ft_free_tab(char **tab);
int						ft_tablen(char **tab);
int						ft_tabncmp(char **env, char **av);
char					*ft_strdup(const char *s1);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_isprint(int c);
void					ft_putendl(char const *s);
void					ft_putnbr(int nb);
void					ft_putstr(char const *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_strlen(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_strsub(char const *s, unsigned int start, size_t l);
int						get_next_line(int const fd, char **line);
char					*get_man_path(void);
int						ft_isdigit(char c);
int						ft_atoi(const char *str);
char					*result_cmd(char *tab);
void					welcome(void);
char					**ft_insert_tab(char **src, char **tab, int i);
void					*ft_memalloc(size_t size);
void					ft_gc(void *p, t_gcop op);
void					ft_bzero(void *s, size_t n);
void					ft_gcrealloc(t_gc **ring, t_gcinfo **in, int init_size);
void					ft_gcinit(t_gc **ring, int init_size, t_gcinfo **info);
char					*ft_itoa(long n);
char					*join_spe_tab(char **tab, int beg, int end);
char					*ft_strnew(size_t size);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					ft_free(void *p);
int						ft_isalpha(char c);
int						isdirectory(char *str);

/*
** ENVIRON
*/
t_env					*add_env(t_env *env, char *name, char *val, int prot);
void					new_env(char **env);
void					print_list(t_env *env);
char					*find_value_envir(t_env *env, char *str);
t_env					*ft_unsetenv(t_env *env, char *str);
t_env					*ft_setenv(t_env *env, char *name, char *value);
char					**make_env_tab(t_env *env);

/*
** BUILTIN
*/

void					ft_echo(char **tab);
int						ft_exit(char **tab);
int						ft_cd(char **tab);
void					load_conf_file(void);
char					**is_alias(t_alias *list, char **tab);
void					ft_alias(char **tab);
t_var					*add_var(t_var *list, char *name, char *value);
t_var					*del_var(t_var *list, char *name);
void					show_var(t_var *list);
void					set_var(char *name, char *value);
void					unset_var(char *name);
void					ft_set(char **tab);
void					export_var(t_var *list, char *name);
void					no_conf(void);
int						check_exit_status(void);
void					no_conf_msg(void);

/*
** MAIN
*/

void					ft_mishell(char *line);
char					**ft_get_path(char **env, char *line);
void					exec_cmd(char **tab);
int						detect_built(char **tab);
int						pre_exec(char *str);
int						pre_exec_nofork(char *str);
int						pre_exec_nowait(char *str);
void					main_options(char **av, int *choice);
void					child(char **tab);
int						is_operator(char **tab);

/*
** PROMPT
*/
void					basic_prompt(void);
void					prompt(void);
void					prompt_interpreter(char *str);
void					show_time(void);
void					prompt_termcaps(char *str);
void					show_value_envir(char *str);
int						show_color(char *str, int i);

/*
** PIPE
*/
int						check_redirection(char **tab);
void					infile(char *str);
char					**re_tab(char **tab, int i);
void					outfile(char *str);
void					spe_outfile(char *str);
void					go_pipe(char **tab);
t_command				*split_pipe(t_command *list);
char					**join_tab(char **tab);
void					spe_infile(char *str);

/*
** SIGNALS
*/

void					interrupt_process(int s);
void					interrupt_cmd(int s);

/*
** JOBS
*/

t_jobs					*add_job(t_jobs *list, char *name, int pid);
t_jobs					*remove_jobs(t_jobs *jobs, int pid);
void					show_jobs(t_jobs *jobs);
void					check_return(int ret, int pid);
void					show_stop(int sig);
char					*find_prog(t_jobs *jobs, int pid);
void					fg_bg(t_jobs *jobs, char **tab, int k);
int						search_job(t_jobs *jobs, char *tab, int rt);
void					job_continued(int job, char *name);
int						is_digit(char *tab);
int						find_pid(t_jobs *jobs);

/*
** OPERATORS
*/

void					check_operators(char **tab, int i);

#endif
