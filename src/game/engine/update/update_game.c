/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:12:11 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:15:23 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		update_game(t_cub *game)
{
	if (game->entity[0].world.obj != &game->world[(int)game->entity[0].world.id])
		game->entity[0].world.obj = &game->world[(int)game->entity[0].world.id];
	update_player(&game->entity[0]);
	update_entities(game);
	return (1);
}
