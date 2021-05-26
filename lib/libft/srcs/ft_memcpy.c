/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:25:37 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 12:05:17 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	void	*dst_addr;

	dst_addr = dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (dst_addr);
}
