/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gchelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:09:09 by mfaye             #+#    #+#             */
/*   Updated: 2014/03/13 08:47:40 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_gcinfo	*ft_gcinitinfo(void)
{
	t_gcinfo	*out;

	if ((out = (t_gcinfo *)malloc(sizeof(t_gcinfo))) == NULL)
		return (NULL);
	out->nb = 0;
	out->size = 0;
	out->first_avail = NULL;
	return (out);
}

void		ft_gcrealloc(t_gc **ring, t_gcinfo **info, int init_size)
{
	int		i;
	t_gc	*new;

	i = 0;
	while (i < init_size)
	{
		if ((new = (t_gc *)malloc(sizeof(t_gc))) != NULL)
		{
			new->p = NULL;
			new->next = NULL;
			if (ring != NULL)
				new->next = *ring;
			*ring = new;
			(*info)->first = new;
			(*info)->size++;
			(*info)->first_avail = new;
		}
		i++;
	}
}

void		ft_gcinit(t_gc **ring, int init_size, t_gcinfo **info)
{
	if ((*info = ft_gcinitinfo()) != NULL)
		ft_gcrealloc(ring, info, init_size);
}
