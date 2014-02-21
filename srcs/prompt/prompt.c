/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_interpreter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:55:53 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 16:30:19 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	basic_prompt(void)
{
	if (find_value_envir("USER"))
		ft_putstr(find_value_envir("USER"));
	else
		ft_putstr("user");
	ft_putchar('@');
	if (find_value_envir("GROUP"))
		ft_putstr(find_value_envir("GROUP"));
	else
		ft_putstr("group");
	ft_putstr("-> ");
}

void	prompt(void)
{
	if (find_value_envir("PROMPT"))
		prompt_interpreter(find_value_envir("PROMPT"));
	else
		basic_prompt();
}
