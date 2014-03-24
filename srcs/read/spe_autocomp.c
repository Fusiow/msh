/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_autocomp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:11:46 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/23 14:28:54 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*spe_autocomp(char *cmd, int len, int x)
{
	static t_list	*list; 
	static t_list	*beg; 
	static int		v;
	char			*result;

	if (x == 1)
	{
		v = 0;
		return (NULL);
	}
	if (v == 0)
	{
		list = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"), ':'), list);
		beg = list;
	}
	if (!list)
		list = beg;
	if (list)
	{
		result = list->name;
		list = list->next;
		v++;
		if (len > ft_strlen(result) - 1)
		{
			len -= ft_strlen(result);
			while (len >= 0)
			{
				ft_putstr(tgetstr("le", NULL));
				len--;
			}
		}
		return (result);
	}
	return (cmd);
}
