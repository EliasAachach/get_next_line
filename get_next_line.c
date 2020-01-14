/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:54:13 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/11 22:02:55 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		
	}
	return (0);
}
