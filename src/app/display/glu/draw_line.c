/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:25:04 by antheven          #+#    #+#             */
/*   Updated: 2021/04/21 15:08:27 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		draw_line(t_cub *game, t_point start, t_point end, int color)
{
	t_point	distance;
	t_point	loc;
	double	step;
	int		i;

	distance.x = (end.x - start.x);
	distance.y = (end.y - start.y);
	if (fabs(distance.x) >= fabs(distance.y))
		step = fabs(distance.x);
	else
		step = fabs(distance.y);
	distance.x = distance.x / step;
	distance.y = distance.y / step;
	loc.x = start.x - distance.x;
	loc.y = start.y - distance.y;
	i = 0;
	while (i++ < step)
		buffer_write(game, loc.x += distance.x, loc.y += distance.y, color);
	return (1);
}
