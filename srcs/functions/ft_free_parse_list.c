/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_parse_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:45:03 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/02 18:25:34 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	ft_free_parse_list(t_parse *list)
{
	t_parse		*node;
	t_parse		*temp;

	node = list;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp->str);
		temp->str = NULL;
		free(temp);
		temp = NULL;
	}
	free(node);
	node = NULL;
}
