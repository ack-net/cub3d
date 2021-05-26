/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:45:48 by antheven          #+#    #+#             */
/*   Updated: 2021/05/17 14:34:11 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_scene_validation	scene_validate(char *line)
{
	char				*file_metas[8];
	int					i;
	t_scene_validation	validator;

	validator.is_valid = 0;
	validator.name = "";
	if (!ft_strlen(line))
	{
		validator.is_valid = 1;
		return (validator);
	}
	file_metas[0] = "R";
	file_metas[1] = "NO";
	file_metas[2] = "EA";
	file_metas[3] = "SO";
	file_metas[4] = "WE";
	file_metas[5] = "S";
	file_metas[6] = "F";
	file_metas[7] = "C";
	i = 0;
	while (i < 8)
		if (ft_strnstr(line, file_metas[i++], ft_strlen(line)))
		{
			validator.is_valid = 1;
			validator.name = file_metas[i - 1];
			return (validator);
		}
	return (validator);
}

int					load_scene_data(t_app *app, t_scene_validation *v, char *l)
{
	int		i;
	if (!ft_strlen(l))
		return (1);
	if (!ft_strchr(l, ' ') || !v->name)
		return (0);
	v->values = ft_split(l, ' ');
	i = 0;
	while (v->values[i])
		i++;
	//		printf("[Scene Loader] %d\n", i);
	v->is_valid = 0;
	if (ft_strnstr(v->name, "R", ft_strlen(v->name)))
	{
		if (i == 3)
		{
			//printf("[Scene Loader] setting width & height to %dx%d\n", ft_atoi(v->values[1]), ft_atoi(v->values[2]));
			app->game.resolution.x = ft_atoi(v->values[1]);
			app->game.resolution.y = ft_atoi(v->values[2]);
			v->is_valid = 1;
		}
		else
			v->is_valid = 0;
	}
	if (ft_strlen(v->name) == 2)
	{
	if (!ft_strncmp(v->name, "NO", ft_strlen(v->name)) && i == 2)
		v->is_valid = load_texture(app, v->name, v->values[1]);
	if (!ft_strncmp(v->name, "EA", ft_strlen(v->name)) && i == 2)
		v->is_valid = load_texture(app, v->name, v->values[1]);
	if (!ft_strncmp(v->name, "SO", ft_strlen(v->name)) && i == 2)
		v->is_valid = load_texture(app, v->name, v->values[1]);
	if (!ft_strncmp(v->name, "WE", ft_strlen(v->name)) && i == 2)
		v->is_valid = load_texture(app, v->name, v->values[1]);
	}
	if (ft_strlen(v->name) == 1)
	{
	if (!ft_strncmp(v->name, "S", ft_strlen(v->name)) && i == 2)
		v->is_valid = load_texture(app, v->name, v->values[1]);
	if (!ft_strncmp(v->name, "F", ft_strlen(v->name)) && i == 2)
	{
		char **col = ft_split(v->values[1], ',');
		i = 0;
		while (col[i])
			i++;
		if (i == 3)
			v->is_valid = load_texture_color(app, "FLOOR", create_trgb(0, ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2])));
		else
			v->is_valid = 0;
		i = 0;
		while (col[i])
			free(col[i++]);
		free(col[i++]);
		free(col);
	}
	if (!ft_strncmp(v->name, "C", ft_strlen(v->name)) && i == 2)
	{
		char **col = ft_split(v->values[1], ',');
		i = 0;
		while (col[i])
			i++;
		if (i == 3)
			v->is_valid = load_texture_color(app, "CEIL", create_trgb(0, ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2])));
		else
			v->is_valid = 0;
		i = 0;
		while (col[i])
			free(col[i++]);
		free(col[i++]);
		free(col);
	}
	}

		i = 0;
		while (v->values[i])
			free(v->values[i++]);
		free(v->values[i++]);
		free(v->values);
	return (v->is_valid);
}

int					parse_map(t_app *app, char *line, char ***grid)
{
	t_world	*w = &app->game.world[0];
	char	**new_grid;
	int		i;

	i = 0;
	new_grid = malloc(sizeof(char**)* (w->size.y+1));
	if (w->size.x < ft_strlen(line))
		w->size.x = ft_strlen(line);
	printf("[Grid Parser] %f %f\n", w->size.x, w->size.y+1);
	ft_memmove(new_grid, *grid, w->size.y*sizeof(char**));
	/*while (i < w->size.y)
	{
		//if (*grid[i]){
		printf("[Grid Parser] [%d] << %s\n", i, *((*grid)+i));
		new_grid[i] = malloc(sizeof(char*)* (w->size.x+1));
		ft_strlcpy(new_grid[i], *grid[i], w->size.x+1);//}
		i++;
	}*/
		//printf("[Grid Parser] [%d] << %s\n", i-1, line);
	i = w->size.y;
	w->size.y++;
	*(new_grid + i) = malloc(sizeof(char)* (w->size.x+1));
	ft_strlcpy(new_grid[i], line, w->size.x+1);
	//	printf("[Grid Parser] [%d] << %s\n", i, new_grid[i]);
	//new_grid[i] = 0;
	free(*grid);
	*grid = new_grid;
	return (1);
}

int					load_scene(t_app *app, char *file_path)
{
	int					fd;
	char				*line;
	t_scene_validation	validator;
	char				**grid;

	printf("[Scene Loader] Loading scene '%s'\n", file_path);
	init_loader(app);
	grid = ft_calloc(1, sizeof(char**));
	fd = open(file_path, O_RDONLY);
	if (!fd)
		return (0);
	app->game.world[0].size.x = 0;
	app->game.world[0].size.y = 0;
	while (get_next_line(fd, &line))
	{
		printf("[Scene Loader] << %s\n", line);
		validator = scene_validate(line);
		if (!validator.is_valid)
		{
			if (!parse_map(app, line, &grid))
			{
				printf("[Scene Loader] Invalid line during parsing.\n");
				free(line);
				return (0);
			}
		}
		else
			if (!load_scene_data(app, &validator, line))
			{
				printf("[Scene Loader] Unable to load scene data from instruction '%s'.\n", line);
				free(line);
				return (0);
			}
		free(line);
	}
	if (ft_strlen(line))
	{
		printf("[Scene Loader] << '%s'\n", line);
		if (!parse_map(app, line, &grid))
		{
			printf("[Scene Loader] Invalid line during parsing.\n");
			free(line);
			return (0);
		}
	}
	app->game.world[0].grid = grid;
	free(line);
	close(fd);
	return (1);
}
