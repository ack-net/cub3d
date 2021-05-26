/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:09:13 by antheven          #+#    #+#             */
/*   Updated: 2021/04/29 20:50:31 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		mouse_motion(int x, int y, t_app *app)
{
	//printf("%d - %f = %f\n", x, app->input.mouse.loc.x, x - app->input.mouse.loc.x);
	//printf("%d - %f = %f\n", y, app->input.mouse.loc.y, y - app->input.mouse.loc.y);
	app->input.mouse.dist.x = x - app->input.mouse.loc.x;
	app->input.mouse.dist.y = y - app->input.mouse.loc.y;
	app->input.mouse.loc.x = x;
	app->input.mouse.loc.y = y;
	app->game.entity[0].rotation.yaw += app->input.mouse.dist.x;
	app->game.entity[0].rotation.pitch -= 2*app->input.mouse.dist.y;
	return (1);
}
