/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/02 19:08:02 by lsolofri         ###   ########.fr       */
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
		signal(SIGINT, interrupt_cmd);
		str = take_cmd();
		pre_exec(str, &rt, &ret);
		if (ret == 1)
			break ;
		free(str);
		str = NULL;
	}
	ft_free_env();
	ft_putendl("Goodbye !");
	return (rt);
}
