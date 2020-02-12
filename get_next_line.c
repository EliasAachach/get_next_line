/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/12 19:09:30 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}
	
int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		buf[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.tmp = NULL;
	gnl.str = NULL;
	gnl.len = 0;
	gnl.i = 0;
	gnl.j = 0;
	gnl.pos = 0;
	buf[BUFFER_SIZE] =  '\0';
	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	while ((gnl.ret = read(fd, buf, BUFFER_SIZE)) && (gnl.pos = ft_is_endl(buf)) == -1)
	{
		gnl.len += gnl.ret;
		if (!gnl.tmp)
			gnl.tmp = ft_strdup(buf);
		else
		{
			gnl.str = ft_strjoin(gnl.tmp, buf);
			gnl.tmp = ft_strdup(gnl.str);
		}
	}
	gnl.len += gnl.ret;
	gnl.tmp = ft_substr(buf, 0, gnl.pos);
	gnl.str = ft_strdup(gnl.tmp);
	if (!(*line = (char *)malloc(sizeof(char) * (gnl.len + 1))))
	{
		free (gnl.tmp);
		free (gnl.str);
		return (-1);
	}
	if (gnl.ret == 0)
	{
		ft_free(gnl, line);
		return (0);
	}
	while (gnl.i < gnl.len || gnl.pos != 1)
	{
		line[0][gnl.i] = gnl.str[gnl.i];
		(gnl.i)++;
	}
	line[0][gnl.i] = '\0'
	(gnl.i)++;
	while(gnl.i <= gnl.ret && gnl.str)
	{
		rest[gnl.j] = gnl.str[gnl.i];
		(gnl.i)++;
		(gnl.j)++;
	}
	rest[gnl.j] = '\0';
	return (1);
}