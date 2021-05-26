/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:08:56 by antheven          #+#    #+#             */
/*   Updated: 2021/04/30 10:40:02 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		init_game(t_app *application)
{
	application->game.resolution.x = 800;
	application->game.resolution.y = 600;
	application->game.z_buffer = 0;
	if (application->program.arg_count != 2){
		if (application->program.arg_count == 3 && !ft_strncmp(application->program.arg_values[1], "--save", 6))
		{
			printf("[init_game] Saving image\n");
			return (1);
		}
		printf("Error\n");
		end(application);
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}
