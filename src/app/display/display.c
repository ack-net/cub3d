/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:33:26 by antheven          #+#    #+#             */
/*   Updated: 2021/04/27 12:46:10 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"
#include <stdlib.h>

int		display(t_app *application)
{
	//char	ch[10][512];
	//t_entity *ent;
	t_cub	*game;
	int		i;

	i = 0;
	game = &application->game;
	//ent = &application->game.entity[0];
	render(game);
	//mlx_put_image_to_window(application->display.ptr, application->display.windows[0].win_ptr, game->textures.texture[0].ptr, 300, 300);
	display_buffer(application);
	/*sprintf(ch[0], "Acceleration X:%f", application->game.entity[0].velocity.x);
	sprintf(ch[1], "Acceleration Y: %f", application->game.entity[0].velocity.y);
	sprintf(ch[2], "distance from tile: %f", dda(game, ent->world.obj->grid, ent->world.obj->size, ent->location, vec_add(ent->velocity, 0.1)).distance);
	sprintf(ch[3], "Fov: %f", ent->rotation.fov);
	sprintf(ch[4], "Last Key Pressed: %c(%i)", application->input.keyboard.last_key_pressed, application->input.keyboard.last_key_pressed);
	sprintf(ch[5], ".");
	sprintf(ch[6], ".");
	sprintf(ch[7], ".");
	sprintf(ch[8], ".");
	sprintf(ch[9], ".");*/
	while (i < 10) // x = 250 y = 50 + i * 10
		if (application->output.win_text[i++].visible)
		mlx_string_put (application->display.ptr, application->display.windows[application->output.win_text[i - 1].display].win_ptr, application->output.win_text[i - 1].location.x, application->output.win_text[i - 1].location.y, 0, application->output.win_text[i - 1].text);
//	mlx_string_put (application->display.ptr, application->display.windows[0].win_ptr, 100, 100, 0);//, //ft_itoa(application->game.vars[0]));
//	mlx_string_put (application->display.ptr, application->display.windows[0].win_ptr, 100, 150, 0);//, ft_itoa(application->game.vars[1]));
	return (1);
}
