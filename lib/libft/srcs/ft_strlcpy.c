/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:04:53 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:49:40 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (!dstsize || !dst || !src)
		return (src_len);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
