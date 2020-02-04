/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/04 05:41:17 by elaachac         ###   ########.fr       */
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

int		get_next_line(int fd,char **line)
{
	static char	*rest;
	char		*tmp;
	char		tab[BUFFER_SIZE + 1];
	int			ret;
	int			i;
	int			y;
	
	y = 0;
	i = 0;
	tmp = NULL;
	tab[BUFFER_SIZE] = '\0';
	if ((ret = read(fd, tab, BUFFER_SIZE)) == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else if (ret <= ft_is_endl(tab))
	{
		while (i < ft_is_endl(tab))
		{
			line[0][i] = tab[i];
			i++;
		}
		if ((ret - i) != 0)
		{
			if (!(rest = (char *)malloc(sizeof (char) * (ret - i + 1))))
			{
				free (line);
				return (-1);
			}
			while (tab[i])
				tab[i++] = rest[y++];
		}
		else
			return (1);
	}
	return (0);
}
