/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:38:51 by antheven          #+#    #+#             */
/*   Updated: 2019/10/16 13:48:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_char;

	if (!s)
		return (0);
	if (c == '\0')
	{
		while (*s++ != '\0')
			;
		return ((char*)(s - 1));
	}
	last_char = 0;
	while (*s++)
		if (*(s - 1) == c)
			last_char = (char*)(s - 1);
	return (last_char);
}
