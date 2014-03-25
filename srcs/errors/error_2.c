/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:02:39 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:28:28 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	pid_error(char *tab)
{
	ft_putstr("msh: '");
	ft_putstr(tab);
	ft_putendl("' is not a valid pid");
}

void	job_error(int k)
{
	if (k == 1)
		ft_putstr("fg");
	else
		ft_putstr("bg");
	ft_putendl(": no current job");
}
