/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 11:45:02 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/25 18:58:19 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/msh.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char *)ft_memalloc(sizeof(char) * size)) == NULL)
		return (NULL);
	return (new);
}
