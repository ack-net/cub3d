/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:58:50 by antheven          #+#    #+#             */
/*   Updated: 2019/10/16 14:50:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*number;
	int		nlen;
	int		i;

	i = n;
	nlen = n < 0 ? 2 : 1;
	while (i /= 10)
		nlen++;
	if (!(number = malloc((nlen + 1) * sizeof(char))))
		return (0);
	i = n < 0 ? 1 : 0;
	*(number + nlen) = '\0';
	while (nlen >= 0)
	{
		if (n <= 0)
			*(number + --nlen) = '0' - n % 10;
		if (n > 0)
			*(number + --nlen) = '0' + n % 10;
		n /= 10;
	}
	*number = i ? '-' : *number;
	return (number);
}
