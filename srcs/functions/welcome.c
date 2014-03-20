/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:22:05 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/03 16:23:41 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	welcome(void)
{
	ft_putstr("Welcome to ");
	ft_putstr(GRE);
	ft_putstr("msh");
	ft_putstr(DEF);
	ft_putstr(", the friendly interactive shell !\n");
}
