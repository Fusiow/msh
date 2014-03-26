/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_pimp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 00:16:46 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/26 02:12:32 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/msh.h"

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

void	show_time(void)
{
	char	*result;

	result = result_cmd("date");
	if (result)
		write(1, &result[11], 5);
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
	return (i);
}

void	prompt_termcaps(char *str)
{
	struct termios	term;

	init_flag(&term);
	ft_putstr(tgetstr(str, NULL));
}

void	show_value_envir(char *str)
{
	if (find_value_envir(g_env, str))
		ft_putstr(find_value_envir(g_env, str));
}
