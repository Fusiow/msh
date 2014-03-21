/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:33 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/13 08:43:07 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/msh.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	if ((new = malloc(size)) == NULL)
		return (NULL);
	else
	{
		ft_bzero(new, size);
		ft_gc(new, E_GCADD);
	}
	return (new);
}
