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

char	*spe_autocomp(char *cmd, int len)
{
	static t_list	*list; 
	static t_list	*beg; 
	static int		v;
	static char		*str;
	int				i;
	char			*result;

	i = 0;
	if (v == 0)
	{
		str = ft_strdup(cmd);
		list = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"), ':'), list);
		beg = list;
	}
	if (!list)
		list = beg;
	if (list)
	{
		while (list->name[i] == cmd[i] && list->name[i] && cmd[i])
			++i;
		result = ft_strjoin(str, ft_strsub(list->name, i, ft_strlen(list->name)));
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
		else
		{
			len = ft_strlen(result) - len;
			while (len > 1)
			{
				ft_putstr(" ");
				len--;
			}
		}
		return (result);
	}
	return (cmd);
}
