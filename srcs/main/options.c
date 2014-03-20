#include "../../includes/msh.h"

void		main_options(char **av, int *choice)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!ft_strcmp("-nocolor", av[i]))
			*choice = 1;
		else
		{
			ft_putstr("Unknown option: ");
			ft_putendl(av[i]);
		}
		++i;
	}
}
