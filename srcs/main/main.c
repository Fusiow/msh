/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/25 03:04:08 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int			main(int ac, char **av, char **environ)
{
	char	**tmp;
	int		rt;
	int		ret;

	ret = 0;
	rt = 0;
	(void)ac;
	(void)av;
	new_env(environ);
	load_conf_file();
	while (1)
	{
		prompt();
		tmp = ft_strsplit(take_cmd(), ' ');
		pre_exec(tmp, &rt, &ret);
		if (ret == 1)
			break ;
	}
	ft_putendl("Goodbye !");
	return (rt);
}
