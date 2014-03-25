/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spe_autocomp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:11:46 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 22:23:44 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char	*spe_autocomp2(t_list *list, int len, char *result, int *v)
{
	result = list->name;
	++*v;
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

char	*spe_autocomp(char *cmd, int len, int x)
{
	static t_list	*list;
	static t_list	*beg;
	static int		v;
	char			*result;

	result = NULL;
	if (x == 1)
	{
		v = 0;
		return (NULL);
	}
	if (v == 0)
	{
		list = recup_prog(cmd, ft_strsplit(find_value_envir(g_env, "PATH"),
		':'), list);
		beg = list;
	}
	if (!list)
		list = beg;
	if (list)
	{
		cmd = spe_autocomp2(list, len, result, &v);
		list = list->next;
	}
	return (cmd);
}
