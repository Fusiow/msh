/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 15:53:46 by aardjoun          #+#    #+#             */
/*   Updated: 2014/02/25 01:58:26 by lsolofri         ###   ########.fr       */
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
	new_env(environ);
	if (ac != 1 && av)
		return (-1);
	while (1)
	{
		prompt();
		tmp = ft_strsplit(take_cmd(), ' ');
		if (tmp[0])
		{
			if (detect_built(&rt, tmp, &ret))
			{
				if (fork())
					wait(0);
				else
					exec_cmd(tmp);
			}
			if (ret == 1)
				break ;
		}
	}
	ft_putendl("Goodbye !");
	return (rt);
}
