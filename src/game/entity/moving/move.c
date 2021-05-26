/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:34:41 by antheven          #+#    #+#             */
/*   Updated: 2021/04/16 19:34:41 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		move(t_cub *game, t_entity *entity, int relative_yaw)
{
	double	step_x;
	double	step_y;

	(void)game;
	step_x = cos(degtorad(entity->rotation.yaw - relative_yaw));
	step_y = sin(degtorad(entity->rotation.yaw - relative_yaw));
	//		if ((int)(entity->location.x + entity->velocity.x) < entity->world.obj->size.x)
	//		if ((int)(entity->location.x + entity->velocity.x) >= 0)
	//if (!game->world[entity->world.id].grid[(int)(entity->location.y)][(int)(entity->location.x + entity->velocity.x + 0.1*step_x)])
	if (step_x > 0)
		if (entity->velocity.x < step_x*4)
			entity->velocity.x += 0.02*step_x*2;
	if (step_x <= 0)
		if (entity->velocity.x > step_x*4)
			entity->velocity.x += 0.02*step_x*2;
	if (step_y > 0)
		if (entity->velocity.y < step_y*4)
			entity->velocity.y += 0.02*step_y*2;
	if (step_y <= 0)
		if (entity->velocity.y > step_y*4)
			entity->velocity.y += 0.02*step_y*2;
	//if (entity->velocity.x > step_x && entity->velocity.x < 0)
	//	entity->velocity.x -= 0.01*step_x;
	//		if ((int)(entity->location.x + entity->velocity.y) < entity->world.obj->size.y)
	//		if ((int)(entity->location.x + entity->velocity.y) >= 0)
	//if (!game->world[entity->world.id].grid[(int)(entity->location.y + entity->velocity.y + 0.1*step_y)][(int)(entity->location.x)])
	//if ((entity->velocity.y < step_y && entity->velocity.y > 0) || (entity->velocity.y < step_y && entity->velocity.y < 0))
	//	entity->velocity.y += 0.01*step_y;
	return (1);
}
