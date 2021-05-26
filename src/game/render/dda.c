/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:46:49 by antheven          #+#    #+#             */
/*   Updated: 2021/04/17 11:46:49 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_dda	dda(t_cub *game, char **grid, t_point grid_size, t_point loc, t_point dir)
{
	t_dda	dda;
	t_point	step;
	t_point	side_dist;
	t_point	delta_dist;
	int		hit;
	int		ttl;

	(void)game;
	ttl = 100;
	dda.start = loc;
	dda.end = loc;
	dda.end.x = (int)dda.end.x;
	dda.end.y = (int)dda.end.y;
	hit = 0;
	delta_dist.x = (dir.y == 0) ? 0 : ((dir.x == 0) ? 1 : fabs(1 / dir.x));
	delta_dist.y = (dir.x == 0) ? 0 : ((dir.y == 0) ? 1 : fabs(1 / dir.y));
	if (dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (loc.x - dda.end.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (dda.end.x + 1.0 - loc.x) * delta_dist.x;
	}
	if (dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (loc.y - dda.end.y) * delta_dist.y;
		dda.facing = -1;
	}
	else
	{
		step.y = 1;
		side_dist.y = (dda.end.y + 1.0 - loc.y) * delta_dist.y;
		dda.facing = 1;
	}
	while (!hit)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			dda.end.x += step.x;
			dda.side = 0;
		if (step.x == -1)
			dda.facing = 0;
		else
			dda.facing = 2;
		}
		else
		{
			side_dist.y += delta_dist.y;
			dda.end.y += step.y;
			dda.side = 1;
		if (step.y == -1)
			dda.facing = 3;
		else
			dda.facing = 1;
		}
		if (grid[(int)dda.end.y%(int)grid_size.y][(int)dda.end.x%(int)grid_size.x] || !ttl)
			hit = 1;
		ttl--;
	}
	if (dda.side == 0) dda.distance = (dda.end.x - loc.x + (1 - step.x) / 2) / dir.x;
	else           dda.distance = (dda.end.y - loc.y + (1 - step.y) / 2) / dir.y;
	//dda.facing = dda.side+(game->entity[0].rotation.yaw >= 180 ? 2: 0);
	return (dda);
}
