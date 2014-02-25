/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 03:48:18 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 03:53:25 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		cd_error(char *str)
{
	ft_putstr("cd: ");
	ft_putstr(str);
	if (access(str, F_OK) != -1)
		ft_putendl(": Permission denied.");
	else
		ft_putendl(": Not such file or directory.");
	return (-1);
}
