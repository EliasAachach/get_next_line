#include "get_next_line.h"
#include <fcntl.h>

void    ft_putendl(unsigned char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        str++;
    }
    write(1, "\n", 1);
}

int main()
{
    int		fd;
    char	*line;
	int		i;

	line = NULL;
	fd = open ("oui", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_putendl((unsigned char *)line);
		free(line);
	}
	//ft_putendl((unsigned char *)line);
	free(line);
	close(fd);
	return(0);
}