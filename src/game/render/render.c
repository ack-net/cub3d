/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:10:22 by antheven          #+#    #+#             */
/*   Updated: 2021/04/30 11:28:38 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		draw_minimap(t_cub *game)
{
	t_entity	player;
	t_rotation	player_rot;
	//t_point		ray_start;
	//t_point		ray_end;
	//t_rotation		ray_dir;

	player = game->entity[0];
	player_rot = game->entity[0].rotation;
	//ray_dir = player_rot;
	// ray_start = player.location;
	//ray_start.x *= game->minimap.ratio;
	//ray_start.y *= game->minimap.ratio;
	//ray_end.x = 18.5*game->minimap.ratio;
	//ray_end.y = 1.5*game->minimap.ratio;
					
	//for (int y = 0; y < map_height; y++)
	//	for (int x = 0; x < map_width; x++)
	//		for (int s = 0; s < map_size/3; s++)
	//			vert_line(game, player_loc.x*map_size + map_size/3 / 2 + x*map_size/3+s, player_loc.y*map_size + map_size/3 / 2 + y*map_size/3, player_loc.y*map_size + map_size/3 / 2 + y*map_size/3+map_size/3, map[y][x]*0xFF00F0);
	t_point	step;
	t_point pstep;
	step.x = cos(degtorad(player_rot.yaw));
	step.y = sin(degtorad(player_rot.yaw));
	pstep.x = sin(degtorad(player_rot.yaw)) * (player_rot.fov / 100);
	pstep.y = -cos(degtorad(player_rot.yaw)) * (player_rot.fov / 100);
	t_dda dd;
	int		x = 0;
	while (x < game->resolution.x)
	{
		t_point	ray_dir;
		t_point	camera;

		camera.x = 2 * x / game->resolution.x - 1;
		ray_dir.x = step.x + pstep.x * camera.x;
		ray_dir.y = step.y + pstep.y * camera.x;
		dd = dda(game, game->world[(int)game->entity[0].world.id].grid, game->world[(int)game->entity[0].world.id].size, player.position, vec_mul(ray_dir, 1));
		for (int s = 0; s <= (int)(dd.distance * game->minimap.ratio); s++) // DESSINE LA DIRECTION DE LA CAMERA EN BLEU
			buffer_write(game, player.location.x*game->minimap.ratio + s * ray_dir.x, player.location.y*game->minimap.ratio + s * ray_dir.y, (dd.facing+1)*0x004400);
		//draw_line(game, vec_mul(dd.start, game->minimap.ratio), vec_add(vec_mul(dd.end, game->minimap.ratio), 1), (dd.side + 1) * 0x004400);
		x++;
	}
	for (int y = 0; y < player.world.obj->size.y; y++)
		for (int x = 0; x < player.world.obj->size.x; x++)
			for (int s = 0; s < game->minimap.ratio; s++)
				if (player.world.obj->grid[y][x] > 0)
					vert_line(game, x*game->minimap.ratio+s, y*game->minimap.ratio, y*game->minimap.ratio+game->minimap.ratio, player.world.obj->grid[y][x]*0xFF00F0);
//	for (int s = 0; s < game->minimap.ratio * 2; s++) // DESSINE LA DIRECTION DE LA CAMERA EN BLEU
//		buffer_write(game, player.location.x*game->minimap.ratio + s * step.x, player.location.y*game->minimap.ratio + s * step.y, 0x0000FF);
//	for (int s = -game->minimap.ratio*player_rot.fov/100+1; s < game->minimap.ratio*player_rot.fov/100; s++) // DESSINE LA ZONE RENDUE DE L'ECRAN
//		buffer_write(game, player.location.x*game->minimap.ratio + game->minimap.ratio * player_rot.fov/100 * step.x + s * pstep.x, player.location.y*game->minimap.ratio + game->minimap.ratio * player_rot.fov/100 * step.y + s * pstep.y, 0xFF0000);
//	for (int s = -game->minimap.ratio; s <= game->minimap.ratio; s++) // DESSINE LE PLAN DE LA CAAMERA, EN VIOLET
//		buffer_write(game, player.location.x*game->minimap.ratio+ s * pstep.x, player.location.y*game->minimap.ratio + s * pstep.y, 0xEE00FF);
/*	for (double yaw = player_rot.yaw-player_rot.fov/2; yaw < player_rot.yaw+player_rot.fov/2; yaw+=0.1)
	{ // DESSINE LE CHAMP DE VISION `VIRTUEL` EN VERT
	step.x = cos(yaw * 0.017453);
	step.y = sin(yaw * 0.017453);
		dd = dda(game, game->world[game->entity[0].world.id].grid, game->world[game->entity[0].world.id].size, player_loc, step);
		for (int s = 0; s < dd.distance*game->minimap.ratio; s++)
			buffer_write(game, player_loc.x*game->minimap.ratio + s * step.x, player_loc.y*game->minimap.ratio + s * step.y, 0x004400*(1+dd.side));
		//draw_line(game, dd.start, dd.end, 0xFF0000);
	}*/
	//for (int s = -map_size/2; s <= map_size/2; s++)
	//	vert_line(game, player_loc.x*map_size+s, player_loc.y*map_size-map_size/2, player_loc.y*map_size+map_size/2, 0x00FFFF);
	//for (int s = 0; s < map_size/3; s++)
	//	vert_line(game, player_loc.x*map_size+s + player_loc.x*map_size/3, player_loc.y*map_size + player_loc.y*map_size/3, player_loc.y*map_size+map_size/3 + player_loc.y*map_size/3, 0x00FFFF);
//	draw_line(game, ray_start, ray_end, 0xABCDEF);
	return (1);
}

int		render(t_cub *game)
{
	//int		x_cursor;

	//x_cursor = 0;
	if (!raycast(game))
		return (0);
	if (!draw_sprites(game))
		return (0);
	if (!draw_minimap(game))
		return (0);
	/*while (x_cursor < game->resolution.x)
	{
		x_cursor++;
	}*/
	//+-game->vars[0]%game->resolution.x
	//	vert_line(game, (x_cursor++), 0, game->resolution.y, ((x_cursor * game->vars[0]) % (game->vars[1])) % 0xFFFFFF);
	//game->vars[0]-=100;
	//game->vars[1]=(game->vars[0]+100)%0xFFFFFF;
	return (1);
}
