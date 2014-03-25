/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:52:57 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 16:34:39 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*change_cmd(int i, char *result, char letter)
{
	char	*tmp;
	char	*end;
	char	*c;
	char	*new;

	show_autocomplete(NULL, 0);
	spe_argument_completion(NULL, NULL, 1);
	spe_autocomp(NULL, 0, 1);
	c = char_to_string(letter);
	if (!result)
		return (c);
	if (i == ft_strlen(result))
	{
		new = ft_strjoin(result, c);
		ft_free(result);
		ft_free(c);
		return (new);
	}
	else if (i == 0)
	{
		new = ft_strjoin(c, result);
		ft_free(c);
		ft_free(result);
		return (new);
	}
	else
	{
		tmp = ft_strsub(result, 0, i);
		end = ft_strsub(result, i, ft_strlen(result));
		new = ft_strdup(tmp);
		ft_free(tmp);
		tmp = ft_strjoin(new, c);
		ft_free(result);
		result = ft_strjoin(tmp, end);
		ft_free(end);
		ft_free(tmp);
		ft_free(c);
	}
	return (result);
}

int		distrib_buttons(int i, char **result, char *buffer, int *v)
{
	char	*tmp;

	if (buffer[0] == 10)
		return (-2);
	else if (buffer[0] == 27 && buffer[1] == 91)
	{
		if (*result)
			i = arrow(i, buffer[2], ft_strlen(*result), result);
		else
			i = arrow(i, buffer[2], 0, result);
		if (buffer[2] != 65 && buffer[2] != 66)
			*v = 1;
	}
	else if (buffer[0] == 127)
		*result = del_c(*result, &i);
	else if (buffer[0] == 9 && *result && i == ft_strlen(*result))
	{
		tmp = ft_strdup(*result);
		*result = show_autocomplete(*result, 1);
		if (ft_strcmp(*result, tmp))
			i = ft_strlen(*result);
		else
		{
			*result = tmp;
			ft_putstr(tgetstr("le", NULL));
			i = ft_strlen(tmp);
		}
	}
	else if (buffer[0] == 12)
	{
		ft_putstr(tgetstr("cl", NULL));
		prompt();
	}
	else if (buffer[0] == 1)
	{
		if (i != 0)
		{
			i = 0;
			replace_cursor(i, ft_strlen(*result));
		}
	}
	else if (buffer[0] == 5)
	{
		while (i + 1 < ft_strlen(*result))
		{
			ft_putstr(" ");
			++i;
		}
		i = ft_strlen(*result);
	}
	else if (buffer[0] == 21)
	{
		clear_line(i + 1, ft_strlen(*result));
		*result = NULL;
		i = 0;
	}
	else if (buffer[0] == 11 && *result && i < ft_strlen(*result))
		*result = ft_strsub(*result, 0, i++);
	else if (buffer[0] == 4)
			ft_exit(NULL);
	return (i);
}

char	*take_cmd(int choice)
{
	char			*result;
	char			*buffer;
	struct termios	term;
	int				i;
	int				v;

	i = 0;
	(void)choice;
	init_flag(&term);
	buffer = (char *)ft_memalloc(sizeof(char) * 3);
	result = NULL;
	while (1)
	{
		if (!result)
			i = 0;
		v = 0;
		buffer = init_buffer(buffer);
		read(0, buffer, 3);
		if (ft_isprint(buffer[0]))
			result = change_cmd(i++, result, buffer[0]);
		else
			i = distrib_buttons(i, &result, buffer, &v);
		if (i == -2)
			break;
		if (v == 0 && result)
		{
			clear_line(i, ft_strlen(result));
			if (choice == 0)
				write_cmd(result, 0, 0);
			else
				ft_putstr(result);
			replace_cursor(i, ft_strlen(result));
			if (!result[0])
				result = NULL;
		}
	}
	ft_putstr("\n");
	ft_free(buffer);
	show_autocomplete(NULL, 0);
	re_flag(&term);
	return (result);
}
