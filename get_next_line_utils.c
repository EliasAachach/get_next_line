/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:22:23 by elaachac          #+#    #+#             */
/*   Updated: 2020/03/05 18:29:00 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	while (s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_realloc (void *ptr, size_t size, size_t old_size)
{
	void *tmp;
	
	if ((tmp = (void *)malloc(sizeof(void) * size)))
		ft_memcpy(tmp, ptr, old_size);
	free (ptr);
	return (tmp);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	str = (unsigned char *)src;
	str2 = (unsigned char *)dest;
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dest);
}