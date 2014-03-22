/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 11:45:32 by rkharif           #+#    #+#             */
/*   Updated: 2014/03/22 11:45:56 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/msh.h"

void	ft_free(void *p)
{
	if (p)
		ft_gc(p, E_GCFREE);
}
