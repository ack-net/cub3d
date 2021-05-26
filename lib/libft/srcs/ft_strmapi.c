/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:44:57 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:55:38 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*calc_addr;
	int		strlen;
	int		i;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (!(str = malloc((strlen + 1) * sizeof(char))))
		return (0);
	i = 0;
	calc_addr = str;
	while (strlen--)
		*calc_addr++ = (*f)(i++, *s++);
	*calc_addr = '\0';
	return (str);
}
