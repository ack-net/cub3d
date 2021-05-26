/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:18:54 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:03:41 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		buffer_write(t_cub *game, int x, int y, int color)
{
	char    *dst;

	while (x < 0)
		x += (int)game->resolution.x;
	while (y < 0)
		y += (int)game->resolution.y;
	x = x % (int)game->resolution.x;
	y = y % (int)game->resolution.y;
    dst = game->buffers[game->c_buffer].data + (y * game->buffers[game->c_buffer].size_line + x * (game->buffers[game->c_buffer].bits_per_pixel / 8));
	if (!dst)
		return (0);
    *(unsigned int*)dst = color;
	return (1);
}
