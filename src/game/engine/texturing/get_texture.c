/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:08:56 by antheven          #+#    #+#             */
/*   Updated: 2021/04/30 12:00:30 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_image	get_tex_by_id(t_cub *game, int id)
{
	if (game->textures.tex_lock[id])
		return (game->textures.texture[id]);
	else
		return (game->textures.texture[0]);
}

t_image get_tex_by_name(t_cub *game, char *name)
{
	int		i;
	t_image	texture;

	i = 0;
	while (i++ <= game->textures.n_tex)
	{
		texture = get_tex_by_id(game, i);
		if (ft_strlen(texture.name) == ft_strlen(name))
			if (!ft_strncmp(texture.name, name, ft_strlen(name)))
				return (texture);
	}
	return (get_tex_by_id(game, 0));
}