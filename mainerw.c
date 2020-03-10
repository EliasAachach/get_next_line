#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int			main(void)
{
	/*
	FILE	*fp;
	size_t	len = 0;
	ssize_t	read;
	char	*line;
	fp = fopen("/Users/erwann/Desktop/42/gnl/bob", "r");
	while ((read = getline(&line, &len, fp)) != -1)
		printf("%zd\t%s\n", read, line);
	*/
	char	*line;
	int		fd;
	int		ret;
	int		i;

	fd = open("Rubadub", O_RDONLY);
	line = NULL;
	i = 1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d)\t%d\t%s\n", i, ret, line);
		free(line);
		i++;
	}
	printf("%d)\t%d\t%s\n", i, ret, line);
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}