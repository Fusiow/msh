/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:34:13 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 11:46:06 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	infile(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		show_error("File error.");
	else
		dup2(fd, 0);
	close(fd);
}

void	outfile(char *str)
{
	int		fd;

	fd = open(str, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	dup2(fd, 1);
	close(fd);
}

char	**re_tab(char **tab, int i)
{
	while (tab[i + 2])
	{
		tab[i] = tab[i + 2];
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
