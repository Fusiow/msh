/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_interpreter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 16:30:44 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 18:12:43 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_value_envir(char *str)
{
	if (find_value_envir(str))
		ft_putstr(find_value_envir(str));
}

void	home_pwd(void)
{
	char	*home;
	char	*pwd;

	home = find_value_envir("HOME");
	pwd = find_value_envir("PWD");
	if (home && pwd)
	{
		if (ft_strncmp(home, pwd, ft_strlen(home)) == 0)
		{
			ft_putchar('~');
			write(1, &pwd[ft_strlen(home)], (ft_strlen(pwd) - ft_strlen(home)));
		}
		else
			ft_putstr(pwd);
	}
}


void	prompt_termcaps(char *str)
{
	struct termios	term;

	init_flag(&term);
	ft_putstr(tgetstr(str, NULL));
}

void	interprate_color(char *c)
{
	if (c)
	{
		if (ft_strcmp("RED", c) == 0)
			ft_putstr(RED);
		else if (ft_strcmp("BLUE", c) == 0)
			ft_putstr(BLUE);
		else if (ft_strcmp("GRAY", c) == 0)
			ft_putstr(GRAY);
		else if (ft_strcmp("YEL", c) == 0)
			ft_putstr(YEL);
		else if (ft_strcmp("GRE", c) == 0)
			ft_putstr(GRE);
		else if (ft_strcmp("MAG", c) == 0)
			ft_putstr(MAG);
		else if (ft_strcmp("SBLUE", c) == 0)
			ft_putstr(SBLUE);
		else if (ft_strcmp("DEF", c) == 0)
			ft_putstr(DEF);
	}
}

int		show_color(char *str, int i)
{
	int		v;
	int		j;
	char	*c;
	v = i + 1;
	j = 0;
	while (str[i] != '}' && str[i])
	{
		++i;
		++j;
	}
	c = ft_strsub(str, v, j - 1);
	interprate_color(c);
	free(c);
	return (i);
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
			if (str[i] == 'n')
				show_value_envir("USER");
			else if (str[i] == 'h')
				home_pwd();
			else if (str[i] == 'p')
				show_value_envir("PWD");
			else if (str[i] == 'g')
				show_value_envir("GROUP");
			else if (str[i] == 'u')
				prompt_termcaps("us");
			else if (str[i] == 's')
				prompt_termcaps("mr");
			else if (str[i] == 'e')
				prompt_termcaps("me");
			else if (str[i] == 'c')
				i = show_color(str, i + 1);
			++i;
		}
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			++i;
		}
	}
}
