/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolofri <lsolofri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 19:52:45 by lsolofri          #+#    #+#             */
/*   Updated: 2014/03/25 19:58:39 by lsolofri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

char		*i_equal_len(char *c, char *result)
{
	char	*new;

	new = ft_strjoin(result, c);
	ft_free(result);
	ft_free(c);
	return (new);
}

char		*i_equal_zero(char *c, char *result)
{
	char	*new;

	new = ft_strjoin(c, result);
	ft_free(c);
	ft_free(result);
	return (new);
}

char		*insert_a_char(char *result, char *c, int i)
{
	char	*new;
	char	*tmp;
	char	*end;

	tmp = ft_strsub(result, 0, i);
	end = ft_strsub(result, i, ft_strlen(result));
	new = ft_strdup(tmp);
	ft_free(tmp);
	tmp = ft_strjoin(new, c);
	ft_free(result);
	result = ft_strjoin(tmp, end);
	ft_free(end);
	ft_free(tmp);
	ft_free(c);
	return (result);
}
