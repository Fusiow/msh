/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:54:46 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/28 23:46:01 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	ft_free_env(void)
{
	t_env	*node;
	t_env	*temp;

	node = g_env;
	while (node)
	{
		temp = node;
		node = node->next;
		if (temp->name)
			free(temp->name);
		if (temp->value)
			free(temp->value);
		free(temp);
		temp = NULL;
	}
	free(node);
	node = NULL;
}
