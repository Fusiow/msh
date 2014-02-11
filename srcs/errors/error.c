/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:02:39 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/11 15:14:13 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	show_error_exit(char *str)
{
	write(2, "Error: ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\n", 2);
	exit(0);
}

void	show_error(char *str)
{
	write(2, "Error: ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\n", 2);
}
