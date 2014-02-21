/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 18:56:49 by lsolofri          #+#    #+#             */
/*   Updated: 2014/02/21 19:19:23 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		detect_built(int *rt, char **tab)
{
	int		ret;

	if (!(ret = ft_strcmp("exit", tab[0])))
		*rt = ft_exit(tab, rt);
	else if (!(ret = ft_strcmp("env", tab[0])))
		ft_print_env();
	else if (!(ret = ft_strcmp("setenv", tab[0])))
		ft_setenv(tab);
	else if (!(ret = ft_strcmp("unsetenv", tab[0])))
		ft_unsetenv(tab);
	else if (!(ret = ft_strcmp("echo", tab[0])))
		ft_echo(tab);
	return (ret);
}
