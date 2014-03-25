/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:31:24 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 14:38:04 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		list_len(t_env *env)
{
	int		i;

	i = 0;
	while (env)
	{
		++i;
		env = env->next;
	}
	return (i);
}

char	**make_env_tab(t_env *env)
{
	int		i;
	char	**result;

	i = list_len(env);
	result = (char **)ft_memalloc(sizeof(char *) * i + 1);
	i = 0;
	while (env)
	{
		result[i++] = ft_strjoin(env->name, ft_strjoin("=", env->value));
		env = env->next;
	}
	result[i] = NULL;
	return (result);
}

void	print_list(t_env *env)
{
	while (env)
	{
		ft_putstr(env->name);
		ft_putstr("=");
		if (env->value)
			ft_putendl(env->value);
		else
			ft_putchar('\n');
		env = env->next;
	}
}
