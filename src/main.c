/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:16:42 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 22:04:21 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		main(int ac, char **av)
{
	t_app	app;

	app.display.ptr = mlx_init();
	if (!init_app(ac, av, &app))
		fatal(&app, "App Initialization exception");
	if (!init_game(&app))
		fatal(&app, "Cub Initialization exception");
	if (!load_scene(&app, app.program.arg_values[1]))
		fatal(&app, "Scene Initialization exception");
	if (!init_display(&app))
		fatal(&app, "Mlx Initialization exception");
	start(&app);
	end(&app);
}
