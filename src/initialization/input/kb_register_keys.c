/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_register_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:43:23 by antheven          #+#    #+#             */
/*   Updated: 2021/05/26 16:50:49 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		i(t_app *app)
{
	app->game.vars[0] = (app->game.vars[0] + 1);
	app->game.entity[0].rotation.fov++;
	return (1);
}

int		o(t_app *app)
{
	app->game.entity[0].location.z+=0.05;
	//app->game.vars[1] = app->game.vars[1] + 0.1;
	return (1);
}

int		k(t_app *app)
{
	app->game.vars[0] = (app->game.vars[0] - 1);
	app->game.entity[0].rotation.fov--;
	return (1);
}

int		l(t_app *app)
{
	app->game.entity[0].location.z-=0.05;
	//app->game.vars[1] = (app->game.vars[1] - 0.1) > 0 ? (app->game.vars[1] - 0.1) : app->game.resolution.x;
	return (1);
}

int		w(t_app *app)
{
	move(&app->game, &app->game.entity[0], 0);
	return (1);
}

int		a(t_app *app)
{
	move(&app->game, &app->game.entity[0], 90);
	return (1);
}

int		s(t_app *app)
{
	move(&app->game, &app->game.entity[0], 180);
	return (1);
}

int		d(t_app *app)
{
	move(&app->game, &app->game.entity[0], 270);
	return (1);
}

int		q(t_app *app)
{
	app->game.entity[0].rotation.yaw = ((int)(app->game.entity[0].rotation.yaw - 10 ) % 360);
	return (1);
}

int		e(t_app *app)
{
	app->game.entity[0].rotation.yaw = ((int)(app->game.entity[0].rotation.yaw + 10 ) % 360);
	return (1);
}

int		up(t_app *app)
{
	app->game.entity[0].rotation.pitch = (int)(app->game.entity[0].rotation.pitch + 20);
	return (1);
}

int		down(t_app *app)
{
	app->game.entity[0].rotation.pitch = (int)(app->game.entity[0].rotation.pitch - 20);
	return (1);
}

int		escape(t_app *app)
{
	ft_putendl_fd("esc", 1);
	end(app);
	return (1);
}

int		jump(t_app *app)
{
	app->game.entity[0].process.jump.is_jumping = 1;
	return (1);
}

int		crouch(t_app *app)
{
	ft_putendl_fd("esc", 1);
	end(app);
	return (1);
}

void	kb_register_keys(t_app *application)
{
	kb_register(application, 'i', i);
	kb_register(application, 'k', k);
	kb_register(application, 'o', o);
	kb_register(application, 'l', l);
	kb_register(application, KEY_W, w);
	kb_register(application, KEY_A, a);
	kb_register(application, KEY_S, s);
	kb_register(application, KEY_D, d);
	kb_register(application, KEY_Q, q);
	kb_register(application, KEY_E, e);
	kb_register(application, KEY_LFT, q);
	kb_register(application, KEY_RGT, e);
	kb_register(application, KEY_FWD, up);
	kb_register(application, KEY_BWD, down);
	kb_register(application, KEY_ESC, escape);
	kb_register(application, KEY_SPACE, jump);
	kb_register(application, '/', crouch);
}
