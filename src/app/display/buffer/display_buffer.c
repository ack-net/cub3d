/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:18:28 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:11:14 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		display_buffer(t_app *app)
{
	int		buf_num;

	buf_num = app->game.c_buffer;
	//printf("Displaying buffer %d\n", buf_num);
	mlx_put_image_to_window(app->display.ptr, app->display.windows[0].win_ptr, app->game.buffers[buf_num].ptr, 0, 0);
	app->game.c_buffer = (app->game.c_buffer + 1) % app->game.n_buffers;
	return (1);
}
