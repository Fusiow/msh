/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_interpreter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:55:53 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/25 02:02:48 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

void	basic_prompt(void)
{
	if (find_value_envir(g_env, "USER"))
		ft_putstr(find_value_envir(g_env, "USER"));
	else
		ft_putstr("user");
	ft_putchar('@');
	if (find_value_envir(g_env, "GROUP"))
		ft_putstr(find_value_envir(g_env, "GROUP"));
	else
		ft_putstr("group");
	ft_putstr("-> ");
}

void	prompt(void)
{
	if (find_value_envir(g_env, "PROMPT"))
		prompt_interpreter(find_value_envir(g_env, "PROMPT"));
	else
		basic_prompt();
}
