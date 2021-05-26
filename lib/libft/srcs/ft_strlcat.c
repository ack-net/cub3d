/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:30:48 by antheven          #+#    #+#             */
/*   Updated: 2019/10/16 13:24:50 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnlen(const char *str, int n)
{
	int		len;

	len = 0;
	if (!str || !n)
		return (0);
	while (*str++ && n--)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (!dst || !src || !dstsize)
		return (dst_len + src_len);
	dst += dst_len;
	i = dst_len;
	while (i++ < dstsize - 1 && *src)
		*dst++ = *src++;
	if (dst_len < dstsize)
		*dst = '\0';
	return (dst_len + src_len);
}
