/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:03:57 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:08:34 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		init_loader(t_app *app)
{
	int		i;

	i = 0;
	app->game.textures.n_tex = N_TEXTURES;
	while (i <= N_TEXTURES)
	{
		app->game.textures.tex_lock[i] = 0;
		i++;
	}
	return (1);
}