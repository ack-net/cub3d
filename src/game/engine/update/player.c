/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:17:26 by antheven          #+#    #+#             */
/*   Updated: 2021/04/30 19:30:15 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		update_player(t_entity *player)
{
	if (player->rotation.fov > 180)
		player->rotation.fov = 180;
	if (player->rotation.fov < 15)
		player->rotation.fov = 15;
	if (player->location.x >= player->world.obj->size.x)
		player->location.x = player->world.obj->size.x - 1;
	if (player->location.y >= player->world.obj->size.y)
		player->location.y = player->world.obj->size.y - 1;
	if (player->location.x < 0)
		player->location.x = 0;
	if (player->location.y < 0)
		player->location.y = 0;
	return (1);
}
