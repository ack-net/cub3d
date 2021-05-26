/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:25:50 by antheven          #+#    #+#             */
/*   Updated: 2021/05/01 13:49:38 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		jump_process(t_jmp_prc *jmp_process)
{
	double		step_z;

	step_z = 0.2;
	if (!jmp_process->is_jumping)
		return (1);
	if (!jmp_process->state)
		step_z *= -1;
	printf("jumping %f\n", *(jmp_process->z_offset));
	*(jmp_process->z_offset) += step_z;
	if (*jmp_process->z_offset <= 0.9)
	{
		jmp_process->state = 1;
		*jmp_process->z_offset = 0.9;
		jmp_process->is_jumping = 0;
	}
	if (*jmp_process->z_offset >= 1.9)
		jmp_process->state = 0;
	return (1);
}

int		update_entities(t_cub *game)
{
	int			i;
	t_entity	*ent;

	i = 0;
	while (i < MAX_ENTITIES)
	{
		ent = &game->entity[i++];
		if (ent->is_alive)
		{
		jump_process(&ent->process.jump);
		ent->position.x = ent->location.x;
		ent->position.y = ent->location.y;
		//printf("d:%f\n", ent->neightest_wal_dist*100000);
		double front_dist = dda(game, ent->world.obj->grid, ent->world.obj->size, ent->position, vec_add(ent->velocity, 0)).distance;
			if (ent->neightest_wal_dist*100000 > 1000 || front_dist > 0.00001)
			if ((int)(ent->location.x + ent->velocity.x) < ent->world.obj->size.x)
				if ((int)(ent->location.x + ent->velocity.x) > 0)
					if (ent->world.obj->grid[(int)(ent->location.y)][(int)(ent->location.x + ent->velocity.x)] == 0)
						ent->location.x += ent->velocity.x;
			if (ent->neightest_wal_dist*100000 > 1000 || front_dist > 0.00001)
			if ((int)(ent->location.y + ent->velocity.y) < ent->world.obj->size.y)
				if ((int)(ent->location.y + ent->velocity.y) > 0)
					if (ent->world.obj->grid[(int)(ent->location.y + ent->velocity.y)][(int)(ent->location.x)] == 0)
						ent->location.y += ent->velocity.y;
			if (fabs(ent->velocity.x) > 0)
				ent->velocity.x -= ent->velocity.x*0.3;
			if (fabs(ent->velocity.y) > 0)
				ent->velocity.y -= ent->velocity.y*0.3;
		}
	}
	return (1);
}
