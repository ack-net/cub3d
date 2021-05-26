/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:57:46 by antheven          #+#    #+#             */
/*   Updated: 2021/05/17 14:37:40 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		load_texture(t_app *app, char *tex_name, char *texture_path)
{
	int			i;
	t_tex_list	*tex_list;
	t_image	*tex;

	tex_list = &app->game.textures;
	i = 0;
	while (i < tex_list->n_tex)
	{
		if (!tex_list->tex_lock[i])
		{
			tex_list->tex_lock[i] = 1;
			tex = &tex_list->texture[i];
			tex->size_line = 0;
			tex->name = tex_name;
			tex->type = "MLX";
			//printf("[TXLoder] Loading texture (%d/%d) %s\n", i + 1, N_TEXTURES, texture_path);
			tex->ptr = mlx_xpm_file_to_image(app->display.ptr, texture_path, &tex->width, &tex->height);
			//printf("[TXLoder] Name: %s\n", tex_name);
			//printf("[TXLoder] Size: width=%d;height=%d\n", (int)tex->width, (int)tex->height);
			if (!tex->ptr)
				return (0);
			tex->data = mlx_get_data_addr(tex->ptr, &tex->bits_per_pixel, &tex->size_line, &tex->endian);
			return (1);
		}
		i++;
	}
	return (0);
}

int		load_texture_color(t_app *app, char *tex_name, int color)
{
	int			i;
	t_tex_list	*tex_list;
	t_image	*tex;

	tex_list = &app->game.textures;
	i = 0;
	while (i < tex_list->n_tex)
	{
		if (!tex_list->tex_lock[i])
		{
			tex_list->tex_lock[i] = 1;
			tex = &tex_list->texture[i];
			tex->size_line = 0;
			tex->name = tex_name;
			tex->type = "COLOR";
			//printf("[TXLoder] Loading texture (%d/%d) %s\n", i + 1, N_TEXTURES, texture_path);
			tex->ptr = 0;
			tex->color = color;
			tex->width = 1;
			tex->height = 1;
			tex->bits_per_pixel = 4;
			tex->size_line = 1;
			//printf("[TXLoder] Name: %s\n", tex_name);
			//printf("[TXLoder] Size: width=%d;height=%d\n", (int)tex->width, (int)tex->height);
			return (1);
		}
		i++;
	}
	return (0);
}
