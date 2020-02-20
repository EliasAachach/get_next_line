/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/20 18:30:03 by elaachac         ###   ########.fr       */
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
	buf[BUFFER_SIZE] =  '\0';
	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	while ((gnl.pos = ft_is_endl(gnl.str)) == -1 && ((gnl.ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		gnl.len += gnl.ret;
		if (!gnl.str)
		{
			if ((gnl.str = ft_strdup(buf)) == NULL)
			{
				ft_free(&gnl, line, 0);
				return (-1);
			}
		}
		else
		{
			if ((gnl.str = ft_strjoin(gnl.tmp, buf)) == NULL)
			{
				ft_free(&gnl, line, 0);
				return (-1);
			}
		}
		if ((gnl.tmp = ft_strdup(gnl.str)) == NULL)
		{
			ft_free(&gnl, line, 0);
			return (-1);
		}
	}
	if((gnl.tmp = ft_substr(buf, 0, gnl.pos)) == NULL)
		{
			ft_free(&gnl, line, 0);
			return (-1);
		}
	if ((gnl.str = ft_strdup(gnl.tmp)) == NULL)
	{
		ft_free(&gnl, line, 0);
		return (-1);
	}
	if (!(*line = (char *)malloc(sizeof(char) * (gnl.len + 1))))
	{
		ft_free(&gnl, line, 0);
		return (-1);
	}
	if (gnl.ret == 0)
	{
		ft_free(&gnl, line, 1);
		return (0);
	}
	if (rest)
	{
		while (gnl.i <= ft_strlen(rest))
		{
			line[0][gnl.i] = rest[gnl.i];
			gnl.i++;
		}
	}
	gnl.j = gnl.i;
	putendl(gnl.tmp);
	free(gnl.tmp);
	if ((gnl.tmp = ft_substr(rest, gnl.i, (ft_strlen(rest) - gnl.i))) == NULL)
	{
		return (-1);
	}
	if (rest)
		free(rest);
	if (!(rest = (char *)malloc(sizeof(char) * (gnl.len - gnl.pos + 1))))
	{
		ft_free(&gnl, line, 0);
		return (-1);
	}
	while (gnl.i < gnl.len && gnl.pos != 1)
	{
		line[0][gnl.i] = gnl.str[gnl.j];
		gnl.i++;
		gnl.j++;
	}
	line[0][gnl.i] = '\0';
	gnl.j = 0;
	while(gnl.pos <= gnl.len && buf[gnl.pos])
	{
		rest[gnl.j] = buf[gnl.pos];
		gnl.pos++;
		gnl.j++;
	}
	rest[gnl.j] = '\0';
	return (1);
}