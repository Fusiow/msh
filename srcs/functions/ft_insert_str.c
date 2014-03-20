char		*check_variable(char *str) {
	int		i = 0, v = 0;
	char	*var;

	while (str[i]) {
		if (str[i] == '$') {
			v = i;
			while (str[i] != ' ' && str[i])
				++i;
			var = ft_strsub(str, v, (i - v));
			str = ft_strjoin(ft_strsub(str, 0, v),
				ft_strjoin(var, ft_strsub(str, i, ft_strlen(str) - i)));
		}
		++i;
	}
	return (str);
}
