/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 15:50:30 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/17 20:05:37 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_stop(int sig)
{
	if (sig == 4)
		ft_putstr("Illegal instruction");
	else if (sig == 3)
		ft_putstr("Quit");
	else if (sig == 6)
		ft_putstr("Abort.");
	else if (sig == 8)
		ft_putstr("Floating point exception");
	else if (sig == 9 || sig == 15)
		ft_putstr("Kill");
	else if (sig == 11)
		ft_putstr("Segmentation fault");
	else if (sig == 13)
		ft_putstr("Broken pipe");
	else if (sig == 10 || sig == 7)
		ft_putstr("Bus error");
}
