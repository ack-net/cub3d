/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:36:18 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 16:05:57 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define	BUFFER_SIZE	1024

void			*ft_memset(void *b, int c, unsigned int len);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
void			*ft_memccpy(void *dst, const void *src, int c, unsigned int n);
void			*ft_memmove(void *dst, const void *src, unsigned int len);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
unsigned int	ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
char			*ft_strnstr(const char *src, const char *sch, unsigned int len);
int				ft_atoi(const char *str);
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *s1);
char			*ft_substr(const char *s, unsigned int start, unsigned int len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(int fd, char **line);

#endif
