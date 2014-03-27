/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_interpreter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:30:44 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 15:14:04 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	home_pwd(void)
{
	char	*home;
	char	*pwd;

	home = find_value_envir(g_env, "HOME");
	pwd = find_value_envir(g_env, "PWD");
	if (home && pwd)
	{
		if (ft_strncmp(pwd, "/nfs", 4))
			home = ft_strjoin("/Volumes/DATA", home);
		if (ft_strncmp(home, pwd, ft_strlen(home)) == 0)
		{
			ft_putchar('~');
			write(1, &pwd[ft_strlen(home)], (ft_strlen(pwd) - ft_strlen(home)));
		}
		else
			ft_putstr(pwd);
	}
}

void	prompt_git(void)
{
	char	*result;
	int		i;
	int		v;

	i = 0;
	result = result_cmd("git branch");
	if (result)
	{
		if (ft_strncmp("fatal", result, 5))
		{
			while (result[i] && result[i] != '*')
				++i;
			v = i + 2;
			while (result[i] != '\n' && result[i])
				++i;
			ft_putstr(YEL);
			ft_putstr("(");
			write(1, &result[v], (i - v));
			ft_putstr(")");
			ft_putstr(DEF);
		}
		ft_free(result);
	}
}

void	spe_pwd(char *str)
{
	int		i;
	int		v;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '/')
			{
				ft_putchar(str[i]);
				ft_putchar(str[++i]);
				v = i;
				while (str[i] != '/' && str[i])
					++i;
				if (!str[i])
				{
					v++;
					while (str[v])
						ft_putchar(str[v++]);
				}
				else
					i = v;
			}
			++i;
		}
	}
}

void	check_string(char *str, int *i)
{
	if (str[*i] == 'n')
		show_value_envir("USER");
	else if (str[*i] == 'h')
		home_pwd();
	else if (str[*i] == 'p')
		show_value_envir("PWD");
	else if (str[*i] == 'g')
		show_value_envir("GROUP");
	else if (str[*i] == 'u')
		prompt_termcaps("us");
	else if (str[*i] == 's')
		prompt_termcaps("mr");
	else if (str[*i] == 'e')
		prompt_termcaps("me");
	else if (str[*i] == 'c')
		*i = show_color(str, *i + 1);
	else if (str[*i] == 'G')
		prompt_git();
	else if (str[*i] == 't')
		show_time();
	else if (str[*i] == 'P')
		spe_pwd(find_value_envir(g_env, "PWD"));
}

void	prompt_interpreter(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			check_string(str, &i);
			++i;
		}
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			++i;
		}
	}
}
