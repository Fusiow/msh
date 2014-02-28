/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <aardjoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:47:41 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/28 17:48:22 by aardjoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void		interrupt_process(__attribute__((unused))int s)
{
	ft_putendl("");
}

void		interrupt_cmd(__attribute__((unused))int s)
{
	ft_putendl("");
	prompt();
}
