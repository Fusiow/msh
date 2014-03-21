/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaye <mfaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:09:09 by mfaye             #+#    #+#             */
/*   Updated: 2014/03/21 12:38:36 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

static void	ft_gcadd(void *p, t_gc **ring, t_gcinfo **info)
{
	t_gc	*avail;
//	t_gc	*start;

	if (*ring == NULL)
		ft_gcinit(ring, GC_NBSTART, info);
	if ((*info)->nb + 1 == (*info)->size)
		ft_gcrealloc(ring, info, GC_NBSTART);
	avail = (*info)->first_avail;
	avail->p = p;
//	start = avail;
	(*info)->nb++;
	while (avail)
	{
		if (avail->p == NULL)
		{
			(*info)->first_avail = avail;
			break ;
		}
		if (avail->next == NULL)
			avail = (*info)->first;
		else
			avail = avail->next;
	}
}

static void	ft_gcfree(void *p, t_gcinfo **info)
{
	t_gc	*first;

	if (*info && ((first = (*info)->first) != NULL))
	{
		while (first)
		{
			if (p != NULL && first->p == p)
			{
				free(first->p);
				first->p = NULL;
				(*info)->first_avail = first;
				(*info)->nb--;
				break ;
			}
			else if (p == NULL)
			{
				if (first->p)
					free(first->p);
				first->p = NULL;
				(*info)->first_avail = first;
				(*info)->nb--;
			}
			first = first->next;
		}
	}
}

static void	ft_gcfreegc(t_gcinfo **info)
{
	ft_gcfree(NULL, info);
	free(*info);
}

void		ft_gc(void *p, t_gcop op)
{
	static t_gc		*ring = NULL;
	static t_gcinfo	*info = NULL;

	if (op == E_GCADD)
		ft_gcadd(p, &ring, &info);
	else if (op == E_GCFREE)
		ft_gcfree(p, &info);
	else if (op == E_GCFREEALL)
		ft_gcfree(NULL, &info);
	else
		ft_gcfreegc(&info);
}
