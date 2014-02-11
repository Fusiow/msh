/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 14:52:57 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/11 15:35:50 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*take_cmd(void)
{
	char	*result;
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * 3);
	s.result = (char *)malloc(sizeof(char) * 2058);
	while (1)
	{
		buffer = init_buffer(buffer);
		read(0, buffer, 3);
		if (ft_isprint(buffer[0]))
			/* change value */
		else
			/* buttons */
	}
	ft_putstr("\n");
	free(buffer);
	return (result);
}

char	*read_cmd(void)
{
	struct termios	term;
	char			*result;

	init_flag(&term);
	result = take_cmd();
	re_flag(&term);
	return (result);
}
