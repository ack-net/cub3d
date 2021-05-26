/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:44:52 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:51:00 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	nl;

	if (!haystack)
		return (0);
	nl = ft_strlen(needle);
	if (!nl)
		return ((char*)haystack);
	while (*haystack && len--)
	{
		if (ft_strncmp(haystack, needle, nl) == 0)
			return ((char*)haystack);
		if (len < nl)
			return (0);
		haystack++;
	}
	return (0);
}
