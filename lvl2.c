/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:31:28 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/11 15:00:06 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	static char		*rest;
	char			tab[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;
	int				i;
	int				y;
	
	i = 0;
	y = 1;
	rest = NULL;
	while ((ret = read(fd, tab, BUFFER_SIZE)) > 0)
	{
		tab[BUFFER_SIZE] = '\0';
		if (rest)
			tmp = ft_strjoin(rest,tab);
		else
			tmp = ft_strdup(tab);
		while (tmp[i++] != '\n')
		{
			if (y == 1)
			{
				if (!(*line = (char *)malloc(sizeof (char * ft_strlen(tmp) + 1))))
					return (-1);
				y = 0;
			}
			*line[i] = tmp[i];
		}
		i++;
		if (tmp[i] == '\0')
			return (1);
		else
		{
			i++;
			if (!(rest = (char *)malloc(sizeof (char * (ret - i) + 1))))
				return (-1);
			while (tmp[i] != '\0')
				rest[y++] = tmp[i++];
		}
	}
	return (0);
}
