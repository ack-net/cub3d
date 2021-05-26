/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:32:06 by antheven          #+#    #+#             */
/*   Updated: 2021/03/30 14:32:06 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	end(t_app *application)
{
	int		i;

	i = 0;
	while (i < MAX_STRINGS)
		string_del(&application->output, i++);
	i = 0;
	while (i < application->game.textures.n_tex)
		if (application->game.textures.tex_lock[i++]){
			printf("Destroying texture %i %s\n", i - 1, application->game.textures.texture[i - 1].name);
			if (ft_strncmp(application->game.textures.texture[i - 1].type, "MLX", 3) == 0)
				mlx_destroy_image(application->display.ptr, application->game.textures.texture[i - 1].ptr);
		}
	destroy_all_windows(&application->display);
	i = 0;
	//while (i < application->game.world[0].size.y)
	//	free(application->game.world[0].grid[i++]);
	printf("Destroying display %p\n", application->display.ptr);
	//mlx_destroy_display(application->display.ptr);
	if (application->game.z_buffer)
		free(application->game.z_buffer);
	free(application->display.ptr);
	exit (EXIT_SUCCESS);
}
