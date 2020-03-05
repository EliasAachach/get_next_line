/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:18:55 by elaachac          #+#    #+#             */
/*   Updated: 2020/03/05 18:27:08 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char	*ft_substr(char *s, int start, int len);
int		get_next_line(int fd, char **line);
char 	*ft_realloc(void *ptr, size_t size, size_t old_size);
void	*ft_memcpy(void *des, const void *src, size_t n);
int		ft_strlen(char *s);
char 	*ft_strchr(const char *s, int c);

#endif
