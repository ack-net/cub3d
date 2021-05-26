/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:02:01 by antheven          #+#    #+#             */
/*   Updated: 2019/10/16 14:38:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	contains_char(const char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		trim_len;
	int		tl_e;
	char	*calc_addr;
	char	*trim;
	int		s1_len;

	calc_addr = (char*)s1;
	trim_len = 0;
	tl_e = 0;
	s1_len = ft_strlen(s1);
	while (contains_char(set, s1[--s1_len]) && s1_len)
		tl_e++;
	while (contains_char(set, *calc_addr++))
		trim_len++;
	if (!(trim = malloc((ft_strlen(s1) - trim_len - tl_e + 1) * sizeof(char))))
		return (0);
	calc_addr = trim;
	s1 += trim_len;
	while (s1_len-- - trim_len + 1 > 0)
	{
		*calc_addr++ = *s1++;
	}
	*calc_addr = '\0';
	return (trim);
}
