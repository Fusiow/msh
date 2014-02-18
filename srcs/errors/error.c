/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 15:02:39 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/18 15:46:53 by aardjoun         ###   ########.fr       */
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

void	exit_error(char **tab)
{
	ft_putstr(tab[0]);
	ft_putstr(": Argument '");
	ft_putstr(tab[1]);
	ft_putendl("' must be an integer");
}
