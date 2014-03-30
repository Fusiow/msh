/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 00:46:22 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/27 14:35:41 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_env	*add_env(t_env *env, char *name, char *value, int protect)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp2 = env;
	tmp = (t_env *)ft_memalloc(sizeof(t_env));
	tmp->name = name;
	tmp->value = value;
	tmp->protect = protect;
	tmp->next = NULL;
	if (env == NULL)
		return (tmp);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (env);
}

void	new_env(char **env)
{
	char	**tmp;
	int		i;
	int		protect;

	i = 0;
	while (env[i])
		++i;
	if (i == 0)
		show_error_exit("Could not set environnement");
	while (*env)
	{
		protect = 0;
		tmp = ft_strsplit(*env, '=');
		if (tmp[0] && tmp[1])
		{
			if (!ft_strcmp(tmp[0], "PATH") || !ft_strcmp(tmp[0], "HOME"))
				protect = 1;
			g_env = add_env(g_env, tmp[0], tmp[1], protect);
		}
		env++;
	}
}

char	*find_value_envir(t_env *env, char *str)
{
	while (env != NULL && (ft_strcmp(env->name, str) != 0))
		env = env->next;
	if (env)
		return (env->value);
	else
		return (NULL);
}

t_env	*ft_unsetenv(t_env *env, char *str)
{
	t_env	*tmp;

	if (!env)
		return (NULL);
	if (!str)
		return (env);
	if (!ft_strcmp(env->name, str) && env->protect == 0)
	{
		tmp = env->next;
		ft_free(env);
		tmp = ft_unsetenv(tmp, str);
		return (tmp);
	}
	else
	{
		env->next = ft_unsetenv(env->next, str);
		return (env);
	}
}

t_env	*ft_setenv(t_env *env, char *name, char *value)
{
	if (name && value)
	{
		env = ft_unsetenv(env, name);
		if (!ft_strcmp(name, "MANPATH"))
			env = add_env(env, name, ft_strdup(value), 1);
		else
			env = add_env(env, name, value, 0);
	}
	return (env);
}
