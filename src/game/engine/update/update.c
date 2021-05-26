/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:11:00 by antheven          #+#    #+#             */
/*   Updated: 2021/04/30 11:27:47 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		update(t_app *app)
{
	char	ch[10][512];
	t_cub		*game;
	t_entity	*player;
	t_point		text_loc;
	int		i;

	kb_loop(app);
	game = &app->game;
	player = &game->entity[0];
	update_game(game);
	text_loc.x = 250; // x = 250 y = 50 + i * 10
	text_loc.y = 50;
	sprintf(ch[0], "Acceleration X:%f\n", player->velocity.x);
	sprintf(ch[1], "Acceleration Y: %f\n", player->velocity.y);
	sprintf(ch[2], "distance from tile: %f", dda(game, player->world.obj->grid, player->world.obj->size, player->position, vec_add(player->velocity, 0.1)).distance);
	sprintf(ch[3], "Fov: %f", player->rotation.fov);
	sprintf(ch[4], "Last Key Pressed: %c(%i)", app->input.keyboard.last_key_pressed, app->input.keyboard.last_key_pressed);
	i = 0;
	string_put(&app->output, i++, 0, text_loc, "Last Key Pressed: ", 0);
	text_loc.x += 120;
	string_put(&app->output, i++, 0, text_loc, ft_itoa(app->input.keyboard.last_key_pressed), 1);
	text_loc.x -= 120;
	text_loc.y += 10;
	string_put(&app->output, i++, 0, text_loc, "Distance from neightest wall: ", 0);
	text_loc.x += 200;
	string_put(&app->output, i++, 0, text_loc, ft_itoa((int)(player->neightest_wal_dist*100000)), 1);
	text_loc.x -= 200;
	text_loc.y += 10;
	/*while (i < 5)
	{
		string_put(&app->output, i, 0, text_loc, ch[0]);
		text_loc.y += 10;
		i++;
	}*/
	return (1);
}
