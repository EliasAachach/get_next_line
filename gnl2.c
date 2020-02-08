/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/06 22:25:38 by elaachac         ###   ########.fr       */
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
}													//

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int		get_next_line(int fd,char **line)
{
	static char	*rest;
	char		*tmp;
	char		tab[BUFFER_SIZE + 1];
	int			ret;
	int			ret_total;
	int			i;
	int			y;

	y = 0;
	i = 0;
	tmp = NULL;
	ret_total = 0;
	tab[BUFFER_SIZE] = '\0';
	if ((ret = read(fd, tab, BUFFER_SIZE)) == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else if (ft_is_endl(tab) < 0)
	{
		ret_total = ret;
		while (ft_is_endl(tab) < 0)
		{
			if (!(rest = (char *)malloc(sizeof (char) * ret_total + 1)))
				return (-1);
			while (tab[i])
			{
				rest[i] = tab[i];
				i++;
			}
			rest[i] = '\0';
			if ((ret = read(fd, tab, BUFFER_SIZE)) == 0)
			{
				free(rest);
				return (0);
			}
			else if (ret == -1)
			{
				free(rest);
				return (-1);
			}
			else
				ret_total += ret;
		}
		if (!(line[0] = (char *)malloc(sizeof(char) * ft_strlen(rest) + 1)))
		{
			free(rest);
			return (-1);
		}
		while (rest[y])
		{
			line[0][y] = rest[y];
			y++;
		}
		line[0][y] = '\0';
		free(rest);
		return (1);
	}
	else if (ft_is_endl(tab) <= ret)
	{
		if (!(line[0] = (char *)malloc(sizeof(char) * (ft_is_endl(tab) +
							ft_strlen(rest)))))
		{
			ft_putnbr(ft_is_endl(tab));
			return (-1);
		}
		if (rest)
		{
			while (i < ft_strlen(rest))
				line[0][i] = rest[i];
			i++;
		}
		while ((i - ft_strlen(rest)) < ft_is_endl(tab))
		{
			line[0][i] = tab[i];
			i++;
		}
		line[0][i] = '\0';
		if ((ret - i) != 0)
		{
			if (!(rest = (char *)malloc(sizeof (char) * (ret - i + 1))))
			{
				free (line[0]);
				return (-1);
			}
			while (tab[i])
				tab[i++] = rest[y++];
			rest[y] = '\0';
		}
		return (1);
	}
	return (0);
}
