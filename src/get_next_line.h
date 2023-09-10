/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:04:54 by aelidrys          #+#    #+#             */
/*   Updated: 2023/05/06 07:28:02 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int a);
size_t	ft_strlen(char *s);
void	*ft_calloc(size_t c, size_t s);
char	*ft_strdup(char *s1, int n, char **p);
char	*ft_strdup1(char *s1, int a, int m);
#endif