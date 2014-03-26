/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 05:37:04 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/26 05:47:07 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/msh.h"

int		check_redir(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '>')
			return (1);
		if (str[i] == '>' && str[i + 1] == '<')
			return (1);
		if (str[i] == '>' || str[i] == '<' ||
			(str[i] == '>' && str[i + 1] == '>') ||
			(str[i] == '<' && str[i + 1] == '<'))
		{
			i += 2;
			while (iswhite(str[i]))
				++i;
			if (!str[i])
				return (1);
		}
		++i;
	}
	return (0);
}
