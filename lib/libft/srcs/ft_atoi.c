/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:36:15 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:51:31 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		neg;

	nb = 0;
	neg = 1;
	if (!str)
		return (0);
	while (*str == '\t'
			|| *str == '\n'
			|| *str == '\v'
			|| *str == '\f'
			|| *str == '\r'
			|| *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		neg *= *str == '-' ? -1 : 1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		nb = 10 * nb + (*str++ - '0');
	return (neg * nb);
}
