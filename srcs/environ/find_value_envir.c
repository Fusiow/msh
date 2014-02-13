#include "../../includes/msh.h"

char 	*find_value_envir(char *name)
{
	int 	i;

	i = 0;
	while (ft_strncmp(g_env[i], name, ft_strlen(name)) && g_env[i])
		++i;
	if (g_env[i])
		return (ft_strsub(g_env[i], ft_strlen(name) + 1, ft_strlen(g_env[i])));
	else
		return (NULL);
}
