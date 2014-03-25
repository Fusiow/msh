/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdirectory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 13:28:26 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 13:28:30 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		isdirectory(char *str)
{
	DIR		*dir;

	dir = opendir(str);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
		return (0);
}
