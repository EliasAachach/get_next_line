/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:40:49 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/10 14:30:53 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	int 			ret;
	char			tab[BUFFER_SIZE + 1];
	static char		*rest;
	int 			i;

	i = 0;
	rest = NULL;
	while ((ret = read(fd, tab, BUFFER_SIZE)) > 0)
	{
		tab[BUFFER_SIZE] = '\0';
		while (tab[i])
		{
			if (tab[i] == '\n' && rest == NULL)
			{
				if (!(*line = (char *)malloc(sizeof (char) * ret + 1)))
					return (-1);
				i = 0;
				while (tab[i++] != '\n')
					line[i] = tab[i];
				line[i] = '\0';
			}
			if (tab[i + 1] == '\0')
				return (1);
			else
				{
					if (!(rest = (char *)malloc(sizeof (char) * ret - i + 1)))
						return (-1);
					while (i++ <= ret)
						rest[i] = tab[i];
					rest[i] = '\0';
				}
				i++;
		}
		tmp = ft_strjoin(rest, tab);
		rest = ft_strdup(tmp);
	}
}
