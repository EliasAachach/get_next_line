/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:22:23 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/14 17:16:18 by elaachac         ###   ########.fr       */
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

int		ft_strlen(char *s)
{
	int count;

	count = 0;
	if (!(s))
		return (0);
	while (s[count])
		count++;
	return (count);
}

int		ft_is_endl(char *str)
{
	int count;

	count = 0;
	if(!str)
		return (-1);
	while(str[count++])
	{
		if (str[count] == '\n')
			return (count);
	}
	return (-1);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*s2;

	i = 0;
	if (!s || !(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (len-- && i < ft_strlen(s))
			s2[i++] = s[start++];
	}
	s2[i] = '\0';
	return (s2);
}