/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:00:22 by antheven          #+#    #+#             */
/*   Updated: 2019/10/09 12:47:30 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		unit;

	if (n < 0)
		write(fd, "-", 1);
	if (n / 10)
		ft_putnbr_fd(n < 0 ? -(n / 10) : n / 10, fd);
	unit = '0' + (n < 0 ? -(n % 10) : n % 10);
	write(fd, &unit, 1);
}
