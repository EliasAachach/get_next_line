/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/12 14:31:13 by elaachac         ###   ########.fr       */
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

	gnl.len = 0;
	tab[BUFFER_SIZE] =  '\0';
	if (line == NULL | BUFFER_SIZE <= 0 || (ret = read(fd, NULL, 0) == -1))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE) =! ft_is_endl(buf)))
}
