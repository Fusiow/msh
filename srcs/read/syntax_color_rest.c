/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_color_rest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 13:51:41 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 15:04:45 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	syntax_color_rest(char *str)
{
	int		i;
	int		quote;
	int		s_quote;

	quote = 1;
	s_quote = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			++i;
			while (str[i] != '"' && str[i])
				++i;
			if (!str[i])
				quote = 0;
		}
		else if (str[i] == '\'')
		{
			++i;
			while (str[i] != '\'' && str[i])
				++i;
			if (!str[i])
				s_quote = 0;
		}
		++i;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && quote == 0)
			ft_putstr(RED);
		else if (str[i] == '"' && quote == 1)
		{
			ft_putstr(YEL);
			ft_putchar(str[i++]);
			while (str[i] != '"' && str[i])
				ft_putchar(str[i++]);
			ft_putchar(str[i]);
			ft_putstr(DEF);
			++i;
		}
		else if (str[i] == '\'' && s_quote == 0)
			ft_putstr(RED);
		else if (str[i] == '\'' && s_quote == 1)
		{
			ft_putstr(YEL);
			ft_putchar(str[i++]);
			while (str[i] != '\'' && str[i])
				ft_putchar(str[i++]);
			ft_putchar(str[i]);
			ft_putstr(DEF);
			++i;
		}
		if (*(str + i) != '\0')
		{
			write(1, &str[i], 1);
			++i;
		}
	}
	ft_putstr(DEF);
	free(str);
}
