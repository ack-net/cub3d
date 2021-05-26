/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:13:29 by antheven          #+#    #+#             */
/*   Updated: 2019/10/16 13:55:44 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, unsigned int len)
{
	char	*new_str;
	char	*str_addr;

	if (!s)
		return (0);
	if (!(new_str = malloc((len + 1) * sizeof(char))))
		return (0);
	str_addr = new_str;
	if (start < ft_strlen(s))
	{
		while (start--)
			s++;
		while (len-- && *s)
			*new_str++ = *s++;
	}
	*new_str++ = '\0';
	return (str_addr);
}
