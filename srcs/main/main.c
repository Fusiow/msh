/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/26 21:27:59 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			main(int ac, char **av, char **environ)
{
	char		*str;
	int			rt;
	int			ret;

	ret = 0;
	rt = 0;
	(void)ac;
	(void)av;
	new_env(environ);
	load_conf_file();
	while (1)
	{
		prompt();
		str = take_cmd();
		pre_exec(str, &rt, &ret);
		if (ret == 1)
			break ;
	}
	ft_putendl("Goodbye !");
	return (rt);
}
