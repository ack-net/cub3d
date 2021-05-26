/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:40:23 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:45:08 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned int n)
{
	if (!dst || !src)
		return (0);
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src++;
		if (*(unsigned char*)dst++ == (unsigned char)c)
			return ((void*)dst);
	}
	return (0);
}
