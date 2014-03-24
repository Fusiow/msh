#include "../../includes/msh.h"

int		isdirectory(char *str)
{
	DIR		*dir;

	dir = opendir(str);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
		return (0);
}
