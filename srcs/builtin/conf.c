/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 02:38:17 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 14:19:54 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	load_conf_file(void)
{
	int		fd;
	char	*tmp;

	tmp = ft_strjoin(find_value_envir(g_env, "HOME"), "/.mshrc");
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Je passe ici");
		close(fd);
		no_conf();
		fd = open(tmp, O_RDONLY);
	}
	if (fd != -1)
	{
		while (get_next_line(fd, &tmp))
			pre_exec(tmp);
	}
}
