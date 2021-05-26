/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:50:06 by antheven          #+#    #+#             */
/*   Updated: 2019/10/11 11:04:51 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*clc;
	void			*clc_addr;
	unsigned int	i;

	i = 0;
	if (!(clc = malloc(count * size)))
		return (0);
	clc_addr = clc;
	while (i++ < count * size)
		*(unsigned char*)clc++ = 0;
	return (clc_addr);
}
