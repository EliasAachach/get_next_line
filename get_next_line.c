/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/15 17:59:29 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n_in_tmp(char **line, )
{
	if (!(*line = (char *)malloc(sizeof(char * ft_strlen_to_n(tmp)
						+ 1))))
	{
		free(tmp);
		return (-1);
	}
	while (tmp != '\n')
		*line[y++] = tmp[i++];
	*line[y] = '\0';
	if (!(rest = (char *)malloc(sizeof (char * (ret - i) + 1))))
	{
		free (line);
		free (tmp);
		return (-1);
	}
	y = 0;
	tmp[i++];
	while (tmp[i] != '\0')
		rest[y++] = tmp[i++];
	rest[y] = '\0';
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*rest;
	char			*tmp;
	char			tab[BUFFER_SIZE + 1];
	int				ret;
	int				i;
	int				y;

	i = 0;
	y = 0;
	rest = NULL;
	while ((ret = read (fd, tab, BUFFER_SIZE)) > 0)
	{
		tab[BUFFER_SIZE] = '\0';
		if (rest)
			if (!(tmp = ft_strjoin(rest, tab)))
				return(-1);
			else
				if (!(tmp = ft_strdup(tab)))
					return (-1);
		if (ft_strlen_to_n(tmp) > -1)
		{
			if (!(*line = (char *)malloc(sizeof(char * ft_strlen_to_n(tmp) 
								+ 1))))
			{
				free(tmp);
				return (-1);
			}
			while (tmp != '\n')
				*line[y++] = tmp[i++];
			*line[y] = '\0';
			if (!(rest = (char *)malloc(sizeof (char * (ret - i) + 1))))
			{
				free (line);
				free (tmp);
				return (-1);
			}
			y = 0;
			tmp[i++];
			while (tmp[i] != '\0')
				rest[y++] = tmp[i++];
			rest[y] = '\0';
			return (1);
		}
		else
		{
			if (!(rest = (char *)malloc(sizeof (char * (ret + ft_strlen(rest) 1)))))
			{
				free(tmp);
				return (-1);
			}
			while (tmp)
				rest++ = tmp++;
		}
	}
	return (0);
}
