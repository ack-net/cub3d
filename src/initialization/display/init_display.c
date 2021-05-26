/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:38:47 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 22:03:54 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		init_display(t_app *application)
{
	int		i;

	i = 0;
	//application->display.ptr = mlx_init();
	if (!application->display.ptr)
		return (0);
	kb_init(application);
	init_buffers(application);
	application->display.win_count = WIN_COUNT;
	while (i < WIN_COUNT)
		application->display.win_lock[i++] = 0;
	new_window(application, application->game.resolution.x, application->game.resolution.y, application->program.arg_values[0]);
	//destroy_window(&application->display, new_window(application, 800, 600, application->program.arg_values[0]));
	return (1);
}
