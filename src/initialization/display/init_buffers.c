/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:53:37 by antheven          #+#    #+#             */
/*   Updated: 2021/04/06 17:22:10 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	alloc_buffer(t_app *application, int buf_num)
{
	t_image	*image;

	image = &application->game.buffers[buf_num];
	image->ptr = mlx_new_image(application->display.ptr, application->game.resolution.x, application->game.resolution.y);
	image->data = mlx_get_data_addr(image->ptr, &image->bits_per_pixel, &image->size_line, &image->endian);
}

int		init_buffers(t_app *application)
{
	int		i;

	application->game.n_buffers = N_BUFFERS;
	application->game.c_buffer = 0;
	i = 0;
	while (i < N_BUFFERS)
		alloc_buffer(application, i++);
	return (1);
}
