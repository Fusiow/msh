/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:28:05 by lsolofri          #+#    #+#             */
/*   Updated: 2013/12/27 11:39:12 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);

void	ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
