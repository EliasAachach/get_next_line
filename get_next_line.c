/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/10 16:44:24 by elaachac         ###   ########.fr       */
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
	char		tab[BUFFER_SIZE + 1];
	char		*tmp;
	int			index;
	int 		ret;
	int 		y;
	int			j;
	int 		i;
	int 		len;

	rest = NULL;
	y = 0;
	j = 0;
	i = 0;
	len = 0;
	index = -1;
	tmp = NULL;
	tab[BUFFER_SIZE] = '\0';
	if (fd == -1 || (ret = read(fd, tab, BUFFER_SIZE)) == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else if (ft_is_endl(tab) < 0)
	{
		if (rest)
			tmp = ft_strdup(rest);
		while (ft_is_endl(tab) < 0)
		{
			if (!tmp)
				tmp = ft_strdup(tab);
			else
				tmp = ft_strjoin(tmp, tab);
			read(fd, tab, BUFFER_SIZE);
		}
		if (!(line[0] = (char *)malloc(sizeof (char) * (ft_strlen(tmp) + ft_is_endl(tab) + 1))))
		{
			free (tmp);
			return (-1);
		}
		while (tmp[++index])
			line[0][index] = tmp[index];
		while (y <= ft_is_endl(tab))
		{
			line[0][index++] = tab[y];
			y++;
		}
		line[0][index] = '\0';
		if (!(rest = (char *)malloc(sizeof (char) * (ft_strlen(tab) - ft_is_endl(tab) + 1))))
		{
			free (line[0]);
			free (tmp);
			return (-1);
		}
		while (tab[i])
		{
			rest[i++] = tab[y++];
		}
		return (1);
	}
	else
	{
		if (rest)
			len = ft_is_endl(tab) + ft_is_endl(rest);
		else
			len = ft_is_endl(tab);

		if (!(line[0] = (char *)malloc(sizeof (char) * len + 1)))
			return (-1);
		if (rest)
		{
			putendl("ahhhh");
			while (y < ft_is_endl(rest))
			{
				line[0][i] = rest[y];
				i++;
				y++;
			}
			while (rest)
			{
				putendl("oui");
				tmp[j] = rest[y];
				j++;
				y++;
			}
			putendl(tmp);
		}
		y = 0;
		while (y < ft_is_endl(tab))
		{
			line[0][i] = tab[y];
			i++;
			y++;
		}
		line[0][i] = '\0';
		if (!(rest = (char *)malloc(sizeof(char) * (ft_is_endl(tab) - y))))
		{
			free (line[0]);
			return (-1);
		}
		i = 0;
		while (tab[y])
		{
			rest[i] = tab[y];
			i++;
			y++;
		}
		rest[i] = '\0';
	}
	return (1);
}
