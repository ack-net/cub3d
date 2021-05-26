/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:01:34 by antheven          #+#    #+#             */
/*   Updated: 2021/05/17 14:22:24 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		raycast(t_cub *game)
{
	t_point		step;
	t_point		pstep;
	t_entity	player;
		t_point	ray_dir;
		t_point	camera;

	player = game->entity[0];
	step.x = cos(degtorad(player.rotation.yaw));
	step.y = sin(degtorad(player.rotation.yaw));
	pstep.x = sin(degtorad(player.rotation.yaw)) * degtorad(player.rotation.fov);//(player.rotation.fov / 100);
	pstep.y = -cos(degtorad(player.rotation.yaw)) * degtorad(player.rotation.fov);//(player.rotation.fov / 100);
	t_dda dd;
	game->entity[0].neightest_wal_dist = __INT32_MAX__;
	int		x = 0;

/*	int buffer[8][texHeight][texWidth]; // y-coordinate first because it works per scanline
for(int x = 0; x < texWidth; x++)
  for(int y = 0; y < texHeight; y++)
  {
    int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    //int xcolor = x * 256 / texWidth;
    int ycolor = y * 256 / texHeight;
    int xycolor = y * 128 / texHeight + x * 128 / texWidth;
    buffer[0][y][x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    buffer[1][y][x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    buffer[2][y][x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    buffer[3][y][x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    buffer[4][y][x] = 256 * xorcolor; //xor green
    buffer[5][y][x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    buffer[6][y][x] = 65536 * ycolor; //red gradient
    buffer[7][y][x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  }*/
//FLOOR CASTING
	double posZ = player.location.z * game->resolution.y *((180*2-player.rotation.fov))/(game->resolution.y);
/*	t_point ray_dir0;
	t_point ray_dir1;
		ray_dir0.x = step.x - pstep.x;
		ray_dir0.y = step.y - pstep.y;
		ray_dir1.x = step.x + pstep.x;
		ray_dir1.y = step.y + pstep.y;
	int p;
	t_point cell;
	t_point floorl;
	t_point floor_step;*/
   /* for(int y = 0; y < game->resolution.y; y++)
    {
		p = y - game->resolution.y / 2;
		double rowDistance = posZ / p;
		floor_step.x = rowDistance * (ray_dir1.x - ray_dir0.x) / game->resolution.x;
		floor_step.y = rowDistance * (ray_dir1.y - ray_dir0.y) / game->resolution.x;
		floorl.x = player.location.x + rowDistance * ray_dir0.x;
		floorl.y = player.location.y + rowDistance * ray_dir0.y;
		for(int x = 0; x < game->resolution.x; ++x)
		{
			cell.x = (int)(floorl.x);
			cell.y = (int)(floorl.y);
			floorl.x += floor_step.x;
			floorl.y += floor_step.y;
			unsigned int color;
			int texNum = floorTexture;
			int tx = (int)(get_tex_by_id(game, texNum).width * (floorl.x - cell.x)) & (get_tex_by_id(game, texNum).width - 1);
			int ty = (int)(get_tex_by_id(game, texNum).height * (floorl.y - cell.y)) & (get_tex_by_id(game, texNum).height - 1);

			color = get_pixel_color(get_tex_by_id(game, texNum), tx, ty);
			color = (color >> 1) & 8355711; // make a bit darker
			buffer_write(game, game->resolution.x - x - 1, y, color);

			texNum = ceilingTexture;
			tx = (int)(game->textures.texture[texNum].width * (floorl.x - cell.x)) & (game->textures.texture[texNum].width - 1);
			ty = (int)(game->textures.texture[texNum].height * (floorl.y - cell.y)) & (game->textures.texture[texNum].height - 1);
			color = get_pixel_color(get_tex_by_id(game, texNum), tx, ty);
			color = (color >> 1) & 8355711; // make a bit darker
			buffer_write(game, game->resolution.x - x - 1, game->resolution.y - y - 1, color);
		}
    }*/
	while (x < game->resolution.x)
	{
		camera.x = 2 * x / game->resolution.x - 1;
		ray_dir.x = step.x + pstep.x * camera.x;
		ray_dir.y = step.y + pstep.y * camera.x;
		dd = dda(game, game->world[(int)game->entity[0].world.id].grid, game->world[(int)game->entity[0].world.id].size, player.position, ray_dir);
		if (dd.distance < game->entity[0].neightest_wal_dist){
		game->entity[0].neightest_wal_dist = dd.distance;}
		*(game->z_buffer + x ) = dd.distance;
		int lineHeight = (int)(game->resolution.y / dd.distance*((180*2-player.rotation.fov))/(game->resolution.y));
		int drawStart = -lineHeight /2/** 1.5*/ + game->resolution.y / 2 + player.rotation.pitch + (posZ / dd.distance);
		int drawEnd = lineHeight / 2 + game->resolution.y / 2 + player.rotation.pitch + (posZ / dd.distance);
		if(drawStart < 0)drawStart = 0;
		if(drawEnd < 0)drawEnd = 0;
		if(drawStart >= game->resolution.y)drawStart = game->resolution.y - 1;
		if(drawEnd >= game->resolution.y)drawEnd = game->resolution.y - 1;
		int color = 0xFFFFFF;
		color /= dd.side+1;
		int texNum = dd.facing;//player.world.obj->grid[(int)dd.end.y%(int)player.world.obj->size.y][(int)dd.end.x%(int)player.world.obj->size.x] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if (dd.side == 0) wallX = dd.start.y + dd.distance * ray_dir.y;
		else           wallX = dd.start.x + dd.distance * ray_dir.x;
		wallX -= floor((wallX));
		//	if (player.rotation.yaw > 0 && player.rotation.yaw < 180)
		texNum = texNum%game->textures.n_tex;
		//x coordinate on the texture
		int texX = (int)(wallX * (double)(game->textures.texture[texNum].width));
		texX = game->textures.texture[texNum].width-1 - texX;
		if(dd.side == 0 && ray_dir.x > 0) texX = get_tex_by_id(game, texNum).width - texX - 1;
		if(dd.side == 1 && ray_dir.y < 0) texX = get_tex_by_id(game, texNum).width - texX - 1;
		double texStep = 1.0 * get_tex_by_id(game, texNum).height / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - player.rotation.pitch - (posZ / dd.distance) - game->resolution.y / 2 + lineHeight / 2) * texStep;
		for(int y = drawStart; y<drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & ((int)get_tex_by_id(game, texNum).height - 1);
			texPos += texStep;
			//		printf("x: %d, y:%d, %d\n", texX, texY, game->textures.texture[0].bits_per_pixel);
			if (game->textures.tex_lock[texNum])
			color = get_pixel_color(get_tex_by_id(game, texNum), texX, texY);
			//	        color = *(unsigned int*)(game->textures.texture[texNum].data + (texY%game->textures.texture[texNum].height * game->textures.texture[texNum].size_line + texX%game->textures.texture[texNum].width * (game->textures.texture[texNum].bits_per_pixel / 8)) % (game->textures.texture[texNum].width*game->textures.texture[texNum].height*game->textures.texture[texNum].bits_per_pixel));//buffer[texNum][texY%texHeight][texX%texWidth];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			//t_color cl;
			//cl.color = color >> 1;
			//cl = new_rgba(get_red(cl), get_green(cl), get_blue(cl), 255);//get_alpha(cl));
			//for (double d = 0; d < dd.distance; d++)
			//if (!dd.side)
			//	cl = add_shade(dd.distance/100, cl);*/
			/*unsigned int a = ((unsigned int)color >> 24) & (0xFF);
			unsigned int r = ((unsigned int)color >> 16) & (0xFF);
			unsigned int g = ((unsigned int)color >> 8) & (0xFF);
			unsigned int b = ((unsigned int)color) & (0xFF);
			for (double d = 0; d < dd.distance*10; d++){
			r = r*0.999;
			g = g*0.95;
			b = b*0.95;
			a = a*0.95;}
			color = (a <<24 | r << 16 | g << 8 | b);*/
			//cl = new_rgba(get_red(cl), get_green(cl), get_blue(cl), 255);//get_alpha(cl));
			//printf("%x %x, %x, %x, %x\n", color, a, r, g, b);
			//color = get_color(cl);//(color >> 1) & (0xfefefe/2);//8355711;
			buffer_write(game, game->resolution.x - 1 - x, y, color);
		}

		vert_line(game, game->resolution.x - x, 0, drawStart, get_tex_by_name(game, "CEIL").color);
		//vert_line(game, x, drawStart, drawEnd, color);
		vert_line(game, game->resolution.x - x, drawEnd, game->resolution.y, get_tex_by_name(game, "FLOOR").color);
		/*double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

	int floorTexture = 0;
	int ceilingTexture = 2;
      //4 different wall directions possible
      if(dd.side == 0 && ray_dir.x > 0)
      {
        floorXWall = dd.end.x;
        floorYWall = dd.end.y + wallX;
      }
      else if(dd.side == 0 && ray_dir.x < 0)
      {
        floorXWall = dd.end.x + 1.0;
        floorYWall = dd.end.y + wallX;
      }
      else if(dd.side == 1 && ray_dir.y > 0)
      {
        floorXWall = dd.end.x + wallX;
        floorYWall = dd.end.y;
      }
      else
      {
        floorXWall = dd.end.x + wallX;
        floorYWall = dd.end.y + 1.0;
      }

      double distWall, distPlayer, currentDist;

      distWall = dd.distance;
      distPlayer = 0.0;
		if (drawEnd < 0) drawEnd = game->resolution.y; //becomes < 0 when the integer overflows

      //draw the floor from drawEnd to the bottom of the screenif(drawEnd < 0) drawEnd = h; //becomes < 0 when the integer overflows

      // draw the ceiling from the top of the screen to drawStart
      for(int y = 0; y < drawStart; y++)
      {
        currentDist = (game->resolution.y - (2.0 * posZ)) / (game->resolution.y - 2.0 * (y - player.rotation.pitch));

        double weight = (currentDist - distPlayer) / (distWall - distPlayer)*((180*2-player.rotation.fov))/(game->resolution.y);

        // Some variables here are called floor but apply to the ceiling here
        double currentFloorX = weight * floorXWall + (1.0 - weight) * dd.start.x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * dd.start.y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * get_tex_by_id(game, ceilingTexture).width) & (get_tex_by_id(game, ceilingTexture).width - 1);
        floorTexY = (int)(currentFloorY * get_tex_by_id(game, ceilingTexture).height) & (get_tex_by_id(game, ceilingTexture).height - 1);


		buffer_write(game, game->resolution.x - x, y, (get_pixel_color(get_tex_by_id(game, ceilingTexture), floorTexX, floorTexY)));
      }
      for(int y = drawEnd + 1; y < game->resolution.y; y++)
      {
        currentDist = (game->resolution.y + (2.0 * (posZ+5))) / (2.0 * (y - player.rotation.pitch) - game->resolution.y);

        double weight = (currentDist - distPlayer) / (distWall - distPlayer)*((180*2-player.rotation.fov))/(game->resolution.y);

        double currentFloorX = weight * floorXWall + (1.0 - weight) * dd.start.x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * dd.start.y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * get_tex_by_id(game, floorTexture).width) & (get_tex_by_id(game, floorTexture).width - 1);
        floorTexY = (int)(currentFloorY * get_tex_by_id(game, floorTexture).height) & (get_tex_by_id(game, floorTexture).height - 1);

        int checkerBoardPattern = ((int)currentFloorX + (int)currentFloorY) & 1;
        int floorTexture;
        if(checkerBoardPattern == 0) floorTexture = 0;
        else floorTexture = 0;

		buffer_write(game, game->resolution.x - x, y, (get_pixel_color(get_tex_by_id(game, floorTexture), floorTexX, floorTexY) >> 1) & 8355711);
      }*/
      /*for(int y = drawEnd + 1; y < game->resolution.y; y++)
      {
        currentDist = game->resolution.y / (2.0 * y - game->resolution.y - player.rotation.pitch); //you could make a small lookup table for this instead

        double weight = (currentDist - distPlayer) / (distWall - distPlayer)*((180*2-player.rotation.fov))/(game->resolution.y);

        double currentFloorX = weight * floorXWall + (1.0 - weight) * dd.start.x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * dd.start.y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * get_tex_by_id(game, floorTexture).width) % get_tex_by_id(game, floorTexture).width;
        floorTexY = (int)(currentFloorY * get_tex_by_id(game, floorTexture).height) % get_tex_by_id(game, floorTexture).height;

        //floor
		//buffer_write(game, game->resolution.x - x, y, (get_pixel_color(get_tex_by_id(game, floorTexture), floorTexX, floorTexY) >> 1) & 8355711);
        //buffer[y][x] = (texture[3][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
        //ceiling (symmetrical!)
		buffer_write(game, game->resolution.x - x, game->resolution.y - y, get_pixel_color(get_tex_by_id(game, ceilingTexture), floorTexX, floorTexY));
        //buffer[h - y][x] = texture[6][texWidth * floorTexY + floorTexX];
      }*/
		//for (int s = 0; s < (int)(dd.distance * game->minimap.ratio); s++) // DESSINE LA DIRECTION DE LA CAMERA EN BLEU
		//buffer_write(game, /pstep.x * ((x-game->resolution.x/2)*game->minimap.ratio/game->resolution.x) +/ (player.location.x)*game->minimap.ratio + s * ray_dir.x, /pstep.y * ((x-game->resolution.x/2)*game->minimap.ratio/game->resolution.x) +/ (player_loc.y)*game->minimap.ratio + s * ray_dir.y, (dd.side+1)*0x004400);
		//draw_line(game, vec_mul(dd.start, game->minimap.ratio), vec_mul(dd.end, game->minimap.ratio), (dd.side + 1) * 0x004400);
		//printf("ds:%i;de:%i\n", drawStart, drawEnd);
		//printf("tp\n");
		x++;
	}
	return (1);
}
