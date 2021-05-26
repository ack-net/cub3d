/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:59:13 by antheven          #+#    #+#             */
/*   Updated: 2019/10/10 11:15:35 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (--n)
		if (*s1++ != *s2++)
			return (*(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1));
	return (*s1 - *s2);
}
