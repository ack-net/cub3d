/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:50:20 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:45:52 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	void	*dst_addr;

	if (!dst || !src)
		return (0);
	dst_addr = dst;
	while (len--)
		if (dst > src)
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		else
			*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (dst_addr);
}
