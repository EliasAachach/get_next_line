/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:00:29 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/11 20:47:32 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*rest;
	char			tmp;
	char			tab[BUFFER_SIZE + 1];
	int 			ret;
	int				i;
	int				y;

	i = 0;
	y = 0;
	rest = NULL;
	while ((ret = read(fd, tab, BUFFER_SIZE)) > 0)
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
		while (tmp != '\n')
		{
			if (!(*line = (char *) malloc(sizeof (char * ft_strlen(tmp) + 1))))
			{
				return (-1);
				free (tmp);
			}
			*line++ = tmp++;
		}
		tmp++;
		while (tmp)
		{
			if (!(rest = ft_strdup(tmp)))
			{
				free tmp;
				free line;
				return (-1);
			}
		}
		if (ret < BUFFER_SIZE)
			return (0);
	}
	return (0);
}
