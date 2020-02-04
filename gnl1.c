/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/29 17:04:40 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	line[0][j] = '\0';
	while (++i <= j)
	{
		line[0][i] = tmp[i];
	}
	if (!(rest = (char *)malloc(sizeof (char) * (ret - i + 2))))
	{
		free(line);
		free(tmp);
		return (-1);
	}
	rest[ret - i + 2] = '\0';
	while (tmp[++i] != '\0')
		rest[y++] = tmp[i];
	if (tmp)
		free(tmp);
	if (rest)
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
	int				arret;

	arret = 0;
	tmp = NULL;
	rest = NULL;
	index = -1;
	ret = 0;
	while ((arret = read(fd, tab, BUFFER_SIZE)) > 0 || ft_strlen_to_n(line[0]) > 0)
	{
		ret += arret;
		tab[BUFFER_SIZE] = '\0';
		
		if (rest)
		{
			if (!(tmp = ft_strjoin(rest, tab)))
				return(-1);
		}
		else
			if (!(tmp = ft_strdup(tab)))
				return (-1);
		if (ft_strlen_to_n(tmp) == 0)
		{
			if (!(rest = (char *)malloc(sizeof (char) * (ret + ft_strlen(rest)
								+ 1))))
			{
				free(tmp);
				return (-1);
			}
			while (tmp[++index])
			{
				ft_putchar(tmp[index]);
				rest[index] = tmp[index];
			}
			rest[index] = '\0';
		}
		else
		{
			if (n_in_tmp(line, tmp, rest, ret) == -1)
				return (-1);
			if (ft_strlen_to_n(*line) != 0)
				return (1);
		}
	}
	return (0);
}
