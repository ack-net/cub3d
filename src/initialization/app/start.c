/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:06:32 by antheven          #+#    #+#             */
/*   Updated: 2021/04/06 16:06:32 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	start(t_app *application)
{
	application->game.z_buffer = ft_calloc(sizeof(double), application->game.resolution.x);
	for (int j=0; j< application->game.world[0].size.y;j++)
	{
		printf("[Grid After Parse] [%3d] << ", j);
		for (int i=0; i< application->game.world[0].size.x;i++)
		{
			if (ft_isdigit(application->game.world[0].grid[j][i]))
				application->game.world[0].grid[j][i] -= '0';
			else
			{
				if (ft_strchr("ENWS", application->game.world[0].grid[j][i]))
				{
					application->game.entity[0].location.x = i-2;
					application->game.entity[0].location.y = j-2;
					application->game.entity[0].rotation.yaw = application->game.world[0].grid[j][i];
					application->game.world[0].grid[j][i] = 0;
				}
				else
					application->game.world[0].grid[j][i] = 0;
			}
			printf("%c", ' ' + application->game.world[0].grid[j][i]);
		}
		printf("\n");
	}

	application->input.mouse.loc.x = 0;
	application->input.mouse.loc.y = 0;

application->game.minimap.ratio = 10;

	application->game.vars[0] = 0;
	application->game.vars[1] = 0;
	int i = 0;
	while (i < MAX_ENTITIES)
	{
		application->game.entity[i].process.jump.state = 1;
		application->game.entity[i].process.jump.z_offset = &application->game.entity[i].location.z;
		application->game.entity[i].process.jump.is_jumping = 0;
		application->game.entity[i++].is_alive = 0;
	}
	i = 0;
	application->game.entity[i++].is_alive = 0;
	ft_strlcpy(application->game.entity[0].name, "Player", 15);
	application->game.entity[0].type = CUB_ENT_PLAYER;
	/*application->game.entity[0].location.x = CUB_SPAWN_X;
	application->game.entity[0].location.y = CUB_SPAWN_Y;*/
	application->game.entity[0].location.z = 0.2;
	application->game.entity[0].velocity.x = 0;
	application->game.entity[0].velocity.y = 0;
	application->game.entity[0].world.id = 0;
	application->game.entity[0].rotation.type = 'd';
	application->game.entity[0].rotation.pitch = 0;
	application->game.entity[0].rotation.roll = 0;
	application->game.entity[0].rotation.fov = 75;
	//application->game.entity[0].neightest_wal_dist = 0;
	application->game.entity[0].is_alive = 1;
	application->run = 1;
		printf("Running...\n");
	mlx_loop_hook (application->display.ptr, app_loop, application);
	mlx_loop(application->display.ptr);
}
