#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void ft_putendl(unsigned char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, "\n", 1);
}

int			main()
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open("Rubadub", O_RDONLY);
	/*while*/if ((i = get_next_line(fd, &line)) > 0)
	{
		ft_putendl((unsigned char *)line);
		free(line);
		printf("%d\n", i);
	}
	ft_putnbr(ft_strlen(line));
	ft_putendl((unsigned char *)"segfolte");
	ft_putendl((unsigned char *)line);
	ft_putendl((unsigned char *)"segfolte");
	printf("%d\n", i);
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}
