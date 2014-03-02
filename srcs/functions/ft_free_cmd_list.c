/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 15:28:36 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/02 18:58:16 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	ft_free_cmd_list(t_command *list)
{
	t_command	*node;
	t_command	*temp;
	int			i;

	node = list;
	while (node)
	{
		i = 0;
		temp = node;
		node = node->next;
		ft_free_tab(temp->cmd);
		free(temp);
		temp = NULL;
	}
	free(node);
	node = NULL;
}
