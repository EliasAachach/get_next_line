/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/16 21:04:29 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int nbr;

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

void	ft_putstr(char *s)
{
		write(1, s, ft_strlen(s));
}

int		n_in_tmp(char **line, char *tmp, char *rest, int ret)
{
	int i;
	int y;
	int j;

	j = ft_strlen_to_n(tmp);
	i = -1;
	y = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (j + 1))))
	{
		free(tmp);
		return (-1);
	}
	*line[j] = '\0';
	while (++i <= j)
	{
		line[0][i] = tmp[i];
	}
	if (!(rest = (char *)malloc(sizeof (char) * (ret - i + 1))))
	{
		free(line);
		free(tmp);
		return (-1);
	}
	i++;
	while (tmp[i] != '\0')
		rest[y++] = tmp[i++];
	rest[y] = '\0';
	free(tmp);
	free(rest);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*rest;
	char			*tmp;
	char			tab[BUFFER_SIZE + 1];
	int				ret;
	int				index;

	index = 0;
	ret = 0;
	if ((ret = read (fd, tab, BUFFER_SIZE)) > 0)
	{
		tab[BUFFER_SIZE] = '\0';
		if (rest)
		{
			if (!(tmp = ft_strjoin(rest, tab)))
				return(-1);
		}
		else
			if (!(tmp = ft_strdup(tab)))
				return (-1);
		if (ft_strlen_to_n(tmp) >= 0)
		{
			n_in_tmp(line, tmp, rest, ret);
			}
		else
		{
			if (!(rest = (char *)malloc(sizeof (char) * (ret + ft_strlen(rest) + 1))))
			{
				free(tmp);
				return (-1);
			}
			while (tmp[index])
			{
				rest[index] = tmp[index];
				index++;
			}
		}
	}
	return (0);
}
