/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:28:05 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 18:52:43 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "../../includes/msh.h"

void	ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
