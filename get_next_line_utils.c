/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:22:23 by elaachac          #+#    #+#             */
/*   Updated: 2020/01/16 16:37:08 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!(s2 = ((char *)malloc(sizeof(char) * (ft_strlen(s1) + 1)))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

size_t		ft_strlen(char *s)
{
	size_t count;

	count = 0;
	if (!(s))
		return (0);
	while (s[count])
		count++;
	return (count);
}

size_t		ft_strlen_to_n(char *s)
{
	size_t count;

	count = 0;
	while(s[count])
	{
		if (s[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}
