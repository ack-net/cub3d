/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:35 by antheven          #+#    #+#             */
/*   Updated: 2019/10/08 18:15:16 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_strs;
	char	*joined_strs_addr;
	int		s1_len;
	int		s2_len;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	if (!(joined_strs = malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (0);
	joined_strs_addr = joined_strs;
	while (s1_len--)
		*joined_strs++ = *s1++;
	while (s2_len--)
		*joined_strs++ = *s2++;
	*joined_strs = '\0';
	return (joined_strs_addr);
}
