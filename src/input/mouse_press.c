/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:09:51 by antheven          #+#    #+#             */
/*   Updated: 2021/04/27 20:20:09 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		mouse_press(int button, int x, int y, t_app *app)
{
	(void)x;
	(void)y;
	app->input.mouse.last_btn = button;
	return (1);
}
