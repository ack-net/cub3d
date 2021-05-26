/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:06:43 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 14:40:18 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	if (!n)
		return (0);
	while (n--)
		if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
			n = 0;
	return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
}
