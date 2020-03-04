/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/03/05 00:14:22 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void putendl(char *str)								//
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}													//

void	ft_putnbr(int n)
{	unsigned int nbr;

	nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}													//

void ft_free(t_gnl *gnl, char **line, int free_line)
{
	if (gnl->tmp)
		free(gnl->tmp);
	if (gnl->str)
		free(gnl->str);
	if (free_line == 0)
	{
		if (line)
			free(*line);
	}
}

static	int	get_line(char **rest, char **line, size_t start)
{
	char *tmp;

	if ((tmp = ft_strchr(rest)))
}

static	int	read_fd(int fd, char **line, char **rest)
{
	char	*buf;
	int		total_len;
	int		len;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
		//////
	while ((gnl.ret = read(fd, buf, BUFFER_SIZE)))
	{
		*rest = ft_realloc(*rest, total_len + len + 1, total_len);
		ft_memcpy(*rest + total_len, buf, len);
		*rest[total_len + len] = '\0';
		if (get_line(rest, line, total_len))
			return (ft_free(&gnl, line, 0));
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		buf[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.tmp = NULL;
	gnl.str = NULL;
	gnl.len = ft_strlen(rest);
	gnl.i = 0;
	gnl.j = 0;
	gnl.pos = 0;
	gnl.ret = 0;
	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	while ((gnl.pos = ft_is_endl(gnl.str)) == -1 && ((gnl.ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		return (0);
	}
}