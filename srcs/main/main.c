/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/13 16:26:08 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			main(int ac, char **av, char **environ)
{
	char		*str;

	(void)ac;
	(void)av;
	welcome();
	new_env(environ);
	load_conf_file();
	while (1)
	{
		prompt();
		signal(SIGINT, interrupt_cmd);
		str = take_cmd(0);
		pre_exec(str);
		free(str);
		str = NULL;
	}
	return (0);
}
