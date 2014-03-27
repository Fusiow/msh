/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:52:57 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 17:56:40 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*change_cmd(int i, char *result, char letter)
{
	char	*c;

	show_autocomplete(NULL, 0);
	spe_argument_completion(NULL, NULL, 1);
	spe_autocomp(NULL, 0, 1);
	c = char_to_string(letter);
	if (!result)
		return (c);
	if (i == ft_strlen(result))
		result = i_equal_len(c, result);
	else if (i == 0)
		result = i_equal_zero(c, result);
	else
		result = insert_a_char(result, c, i);
	return (result);
}

int		distrib_buttons(int i, char **result, char *buffer, int *v)
{
	if (buffer[0] == 10)
		return (-2);
	else if (buffer[0] == 27 && buffer[1] == 91)
		i = distrib_arrow(i, result, buffer, v);
	else if (buffer[0] == 127)
		*result = del_c(*result, &i);
	else if (buffer[0] == 9 && *result && i == ft_strlen(*result))
		i = distrib_tab(i, result);
	else if (buffer[0] == 12)
		clear_and_prompt();
	else if (buffer[0] == 1)
		i = ctrl_a(i, result);
	else if (buffer[0] == 5)
		i = ctrl_k(i, result);
	else if (buffer[0] == 21)
	{
		clear_line(i + 1, ft_strlen(*result));
		*result = NULL;
		i = 0;
	}
	else if (buffer[0] == 4)
		ft_exit(NULL);
	else
		ft_putstr(tgetstr("le", NULL));
	return (i);
}

char	*print_line(char *result, int choice, int i)
{
	clear_line(i, ft_strlen(result));
	if (choice == 0)
		write_cmd(result, 0, 0);
	else
		ft_putstr(result);
	replace_cursor(i, ft_strlen(result));
	if (!result[0])
		result = NULL;
	return (result);
}

char	*in_while(char *buffer, int choice)
{
	char	*result;
	int		i;
	int		v;

	i = 0;
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
			break ;
		if (v == 0 && result)
			result = print_line(result, choice, i);
	}
	return (result);
}

char	*take_cmd(int choice)
{
	char			*result;
	char			*buffer;
	struct termios	term;

	init_flag(&term);
	buffer = (char *)ft_memalloc(sizeof(char) * 3);
	result = in_while(buffer, choice);
	ft_putstr("\n");
	ft_free(buffer);
	show_autocomplete(NULL, 0);
	re_flag(&term);
	return (result);
}
