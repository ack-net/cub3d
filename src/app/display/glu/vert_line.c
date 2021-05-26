/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:56:37 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:10:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		vert_line(t_cub *game, int x, int start_y, int end_y, int color)
{
	int		i;

	if (start_y > end_y)
	{
		i = end_y;
		end_y = start_y;
		start_y = i;
	}
	while (start_y <= end_y)
		buffer_write(game, x, start_y++, color);
	return (1);
}
