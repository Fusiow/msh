/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 18:13:32 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/18 16:41:01 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*argument_completion(char *str)
{
	int		i;
	char	*word;
	glob_t	list;

	if (str)
	{
		i = ft_strlen(str);
		while (str[i] != ' ' && i > 0)
			--i;
		word = ft_strsub(str, i + 1, ft_strlen(str) - i);
		glob(ft_strjoin(word, "*"), GLOB_NOCHECK, 0, &list);
		i = 0;
		ft_putstr("\n");
		if (list.gl_pathc == 0)
			return (NULL);
		while (list.gl_pathv[i])
			ft_putendl(list.gl_pathv[i++]);
		prompt();
		ft_putstr("     ");
	}
	return (NULL);
}
