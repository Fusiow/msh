/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:52:57 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/01 00:23:12 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*change_cmd(int i, char *result, char letter)
{
	char	*tmp;
	char	*end;
	char	*c;
	int		save;
	char	*new;

	c = char_to_string(letter);
	if (!result)
	{
		ft_putstr(c);
		new = ft_strdup(c);
		free(c);
		return (new);
	}
	if (i == ft_strlen(result))
	{
		new = ft_strjoin(result, c);
		free(result);
		free(c);
		return (new);
	}
	else if (i == 0)
	{
		new = ft_strjoin(c, result);
		free(result);
		free(c);
		return (new);
	}
	else
	{
		save = ft_strlen(result);
		tmp = ft_strsub(result, 0, i);
		tmp[i] = '\0';
		end = ft_strsub(result, i, save - i);
		new = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		tmp = ft_strjoin(new, c);
		free(new);
		free(result);
		result = ft_strjoin(tmp, end);
		free(end);
		free(tmp);
		free(c);
		result[save + 1] = '\0';
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
	else if (buffer[0] == 9 && ft_strcmp(*result, ""))
	{
		tmp = ft_strdup(*result);
		*result = show_autocomplete(*result);
		if (ft_strcmp(*result, tmp))
			i = ft_strlen(*result);
		else
		{
			*result = tmp;
			ft_putstr(tgetstr("le", NULL));
			i = ft_strlen(tmp);
		}
	}
	return (i);
}

char	*take_cmd(void)
{
	char			*result;
	char			*buffer;
	struct termios	term;
	int				i;
	int				v;

	i = 0;
	init_flag(&term);
	buffer = (char *)malloc(sizeof(char) * 3);
	result = (char *)malloc(sizeof(char) * 2058);
	while (1)
	{
		v = 0;
		buffer = init_buffer(buffer);
		read(0, buffer, 3);
		if (ft_isprint(buffer[0]))
		{
			result = change_cmd(i, result, buffer[0]);
			i = i + 1;
		}	
		else
			i = distrib_buttons(i, &result, buffer, &v);
		if (i == -2)
			break;
		if (v == 0 && result)
		{
			clear_line(i, ft_strlen(result));
			write_cmd(result, 0, 0);
//			ft_putstr(result);
			replace_cursor(i, ft_strlen(result));
		}
	}
	ft_putstr("\n");
	free(buffer);
	history(0, result);
	re_flag(&term);
	return (result);
}
