int		get_next_line(int fd, char **line)
{
	int				i;
	int				y;
	int 			ret;
	char			tab[BUFFER_SIZE + 1];
	char			*tmp;
	static char		*rest;

	i = 0;
	y = 0;
	while ((ret = read(fd, tab, BUFFER_SIZE)) > 0)
	{
		tab[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(rest, tab);
		rest = ft_strdup(tmp);
		while (rest[i])
		{
			if (rest[i] == '\n')
			{
				y = i;
				while (rest[y])
					rest[i++] == rest[y++];
				rest[i] = '\0';
				return (1);
			}
			i++;
		}
	}
	if (!(*line = (char *)malloc(sizeof(char) * ft_strlen(rest) + 1)))
		return (-1);
	i = 0;
	while (rest[i])
	{
		line[i] = rest[i];
	}
	return (0);
}
