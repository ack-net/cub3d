/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:05:27 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:51:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		strlen;

	if (!s1)
		return (0);
	strlen = ft_strlen(s1);
	if (!(s2 = malloc((strlen + 1) * sizeof(char))))
		return (0);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 - strlen);
}
