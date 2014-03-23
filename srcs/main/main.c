/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/03/23 14:34:46 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			main(int ac, char **av, char **environ)
{
	char		*str;
	int			choice;

	choice = 0;
	welcome();
	new_env(environ);
	load_conf_file();
	g_env = ft_setenv(g_env, "MANPATH", get_man_path());
	if (ac != 1)
		main_options(av, &choice);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	while (1)
	{
		prompt();
		signal(SIGINT, interrupt_cmd);
		str = take_cmd(choice);
		pre_exec(str);
		free(str);
		str = NULL;
	}
	return (0);
}
