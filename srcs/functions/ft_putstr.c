/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:03:26 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:56:43 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/msh.h"

void	ft_putstr(char const *str)
{
	write(1, str, ft_strlen(str));
}
