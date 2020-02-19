/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 15:18:55 by elaachac          #+#    #+#             */
/*   Updated: 2020/02/18 13:57:03 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_gnl
{
	char	*tmp;
	char	*str;
	int		len;
	int 	ret;
	int		pos;
	int		i;
	int		j;
}				t_gnl;

char	*ft_substr(char *s, int start, int len);
int		get_next_line(int fd, char **line);
int		ft_strlen_to_n(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_is_endl(char *str);

#endif
