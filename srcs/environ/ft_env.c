/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 00:46:22 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/16 17:16:39 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

t_env	*add_env(t_env *env, char *name, char *value)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp2 = env;
	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->name = name;
	tmp->value = value;
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
	int	i;

	i = 0;
	while (env[i])
		++i;
	if (i == 0)
		show_error_exit("Could not set environnement");
	while (*env)
	{
		tmp = ft_strsplit(*env, '=');
		if (tmp[0] && tmp[1])
			g_env = add_env(g_env, tmp[0], tmp[1]);
		env++;
	}
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
	if (!ft_strcmp(env->name, str))
	{
		tmp = env->next;
		free(env);
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
	env = ft_unsetenv(env, name);
	env = add_env(env, name, value);
	return (env);
}

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
