/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 21:54:49 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 22:14:57 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*make_cmd(char *str)
{
	int		i;

	i = 0;
	while (ft_isalpha(str[i]) && str[i])
		++i;
	return (ft_strsub(str, 0, i));
}

int		list_prog_len(t_list *list)
{
	int		i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i);
}

char	*status_equal_zero(char *tmp, char *str, int i, int status)
{
	(void)status;
	if (i == 0 && tmp[0] != '.' && tmp[0] != '/')
		tmp = show_tab(tmp);
	else if (tmp[0] == '-')
	{
		if (!tmp[1])
			show_diff_option(make_cmd(str));
	}
	else
		tmp = argument_completion(tmp, str);
	return (tmp);
}

char	*status_equal_one(char *tmp, char *str, int i)
{
	if (i == 0 && tmp[0] != '.' && tmp[0] != '/')
		tmp = spe_autocomp(str, ft_strlen(str), 0);
	else if (tmp[0] != '-')
		tmp = spe_argument_completion(tmp, str, 0);
	return (tmp);
}

char	*show_command_complete(char *tmp, int i, char *str)
{
	if (ft_strcmp(tmp, "ok") && tmp[0] != '-')
	{
		i = ft_strlen(tmp) - 1;
		while (i-- > ft_strlen(str))
			ft_putstr(tgetstr("nd", NULL));
		str = tmp;
	}
	else
	{
		if (tmp[0] == '-' && tmp[1])
			return (str);
		prompt();
		i = 0;
		while (i++ < ft_strlen(str))
			ft_putstr(" ");
	}
	return (str);
}
