/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 02:38:17 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 02:57:44 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	load_conf_file(void)
{
	int		fd;
	char	*tmp;
	int		not;

	tmp = ft_strjoin(find_value_envir(g_env, "HOME"), "/.mshrc");
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Conf file error");
		return ;
	}
	free(tmp);
	while ((tmp = get_next_line(fd)))
	{
		pre_exec(ft_strsplit(tmp, ' '), &not, &not);
	}
}
