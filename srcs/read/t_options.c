/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_options.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 12:59:04 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/14 17:00:13 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_option	*add_option(t_option *list, char option, char *description)
{
	t_option	*tmp;
	t_option	*temp;

	temp = list;
	tmp = malloc(sizeof(t_option));
	tmp->option = option;
	if (description)
		tmp->description = ft_strdup(description);
	else
		tmp->description = NULL;
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = tmp;
	}
	return (list);
}
