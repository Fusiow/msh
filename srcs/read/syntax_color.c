#include "../../includes/msh.h"

t_list	*add_type(t_list *list, char *str, char *type)
{
	t_list	*tmp;
	t_list	*temp;

	temp = list;
	tmp = malloc(sizeof(t_list));
	tmp->name = strdup(str);
	tmp->type = strdup(type);
	tmp->next = NULL;
	if (list == NULL)
		return (tmp);
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = tmp;
	}
	return (list);
}

t_list	*recup_prog(char *str, char **tab, t_list *list)
{
	int		i;
	DIR		*rep;
	struct dirent	*show;

	i = 0;
	while (tab[i])
	{
		rep = opendir(tab[i++]);
		while ((show = readdir(rep)))
		{
			if (ft_strncmp(str, show->d_name, ft_strlen(str)) == 0)
				list = add_type(list, show->d_name, "Executable");
		}
		closedir(rep);
	}
	return (list);
}

void	show_cmd(char *str)
{
	int	i;
	char	*cmd;
	t_list	*list;

	i = 0;
	list = NULL;
	while (str[i] != ' ' && str[i])	
		++i;
	cmd = ft_strsub(str, 0, i);
	list = recup_prog(cmd, ft_strsplit(getenv("PATH"), ':'), list);
	while (list)
	{
		if (ft_strcmp(cmd, list->name) == 0)
		{
			ft_putstr(BLUE);
			break ;
		}
		list = list->next;
	}
	if (!list)
		ft_putstr(RED);
	ft_putstr(cmd);
	ft_putstr(DEF);
	if ((ft_strlen(str) - i) != 0)
		ft_putstr(ft_strsub(str, i, ft_strlen(str) - i));
//	free(list);
//	free(cmd);
}
