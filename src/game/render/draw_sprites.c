/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:32:01 by antheven          #+#    #+#             */
/*   Updated: 2021/05/17 14:28:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"


//sort algorithm
//sort the sprites based on distance
void sortSprites(int* order, double* dist, int amount)
{
	int		i;
	int		j;
	double	swap;

	j = 0;
	while (j++ < amount)
	{
	i = 1;
	while (i < amount)
	{
		if (dist[i] > dist[i - 1])
		{
			swap = dist[i];
			dist[i] = dist[i - 1];
			dist[i - 1] = swap;
			swap = (int)order[i];
			order[i] = order[i - 1];
			order[i - 1] = (int)swap;
		}
		i++;
	}
	}
	j = 0;
	/*printf("--start--\n");
	while (j < amount)
	{
		printf("[%d]:%f\n", order[j], dist[j]);
		j++;
	}
	printf("--end--\n");*/
 /* std::vector<std::pair<double, int>> sprites(amount);
  for(int i = 0; i < amount; i++) {
    sprites[i].first = dist[i];
    sprites[i].second = order[i];
  }
  std::sort(sprites.begin(), sprites.end());
  // restore in reverse order to go from farthest to nearest
  for(int i = 0; i < amount; i++) {
    dist[i] = sprites[amount - i - 1].first;
    order[i] = sprites[amount - i - 1].second;
  }
}*/
}

int		draw_sprites(t_cub *game)
{
	t_entity player;

	player = game->entity[0];
typedef	struct s_sprite
{
  double x;
  double y;
  int texture;
} t_sprite;

#define numSprites 19

t_sprite sprite[numSprites] =
{
  {20.5, 11.5, 10}, //green light in front of playerstart
  //green lights in every room
  {18.5,4.5, 10},
  {10.0,4.5, 10},
  {10.0,12.5,10},
  {3.5, 6.5, 10},
  {3.5, 20.5,10},
  {3.5, 14.5,10},
  {14.5,20.5,10},

  //row of pillars in front of wall: fisheye test
  {18.5, 10.5, 9},
  {18.5, 11.5, 9},
  {18.5, 12.5, 9},

  //some barrels around the map
  {21.5, 1.5, 8},
  {15.5, 1.5, 8},
  {16.0, 1.8, 8},
  {16.2, 1.2, 8},
  {3.5,  2.5, 8},
  {9.5, 15.5, 8},
  {10.0, 15.1,8},
  {10.5, 15.8,8},
};

//arrays used to sort the sprites
int spriteOrder[numSprites];
double spriteDistance[numSprites];

	t_point		step;
	t_point		pstep;
	//SPRITE CASTING
    //sort sprites from far to close
    for(int i = 0; i < numSprites; i++)
    {
      spriteOrder[i] = i;
      spriteDistance[i] = ((player.location.x - sprite[i].x) * (player.location.x - sprite[i].x) + (player.location.y - sprite[i].y) * (player.location.y - sprite[i].y)); //sqrt not taken, unneeded
    }
	step.x = cos(degtorad(player.rotation.yaw));
	step.y = sin(degtorad(player.rotation.yaw));
	pstep.x = sin(degtorad(player.rotation.yaw)) * degtorad(player.rotation.fov);//(player.rotation.fov / 100);
	pstep.y = -cos(degtorad(player.rotation.yaw)) * degtorad(player.rotation.fov);//(player.rotation.fov / 100);
    sortSprites(spriteOrder, spriteDistance, numSprites);

    //after sorting the sprites, do the projection and draw them
    for(int i = 0; i < numSprites; i++)
    {
      //translate sprite position to relative to camera
      double spriteX = sprite[spriteOrder[i]].x - player.location.x;
      double spriteY = sprite[spriteOrder[i]].y - player.location.y;

      //transform sprite with the inverse camera matrix
      // [ planeX   dirX ] -1                                       [ dirY      -dirX ]
      // [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
      // [ planeY   dirY ]                                          [ -planeY  planeX ]

      double invDet = 1.0 / (pstep.x * step.y - step.x * pstep.y); //required for correct matrix multiplication

      double transformX = invDet * (step.y * spriteX - step.x * spriteY);
      double transformY = invDet * (-pstep.y * spriteX + pstep.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

      int spriteScreenX = (int)((game->resolution.x / 2) * (1 + transformX / transformY));
int posZ =  player.location.z * game->resolution.y *((180*2-player.rotation.fov))/(game->resolution.y);
int vMoveScreen = (int)(-220 / transformY) + player.rotation.pitch + posZ / transformY;
      //calculate height of the sprite on screen
      int spriteHeight = abs((int)(game->resolution.y / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      //calculate lowest and highest pixel to fill in current stripe
      int drawStartY = -spriteHeight / 2 + game->resolution.y / 2 + vMoveScreen;// + player.rotation.pitch + (posZ / game->z_buffer[stripe]);
      if(drawStartY < 0) drawStartY = 0;
      int drawEndY = spriteHeight / 2 + game->resolution.y / 2 + vMoveScreen;// + player.rotation.pitch + (posZ / dd.distance);
      if(drawEndY >= game->resolution.y) drawEndY = game->resolution.y - 1;

      //calculate width of the sprite
      int spriteWidth = abs( (int) (game->resolution.y / (transformY)));
      int drawStartX = -spriteWidth / 2 + spriteScreenX;
      if(drawStartX < 0) drawStartX = 0;
      int drawEndX = spriteWidth / 2 + spriteScreenX;
      if(drawEndX >= game->resolution.x) drawEndX = game->resolution.x - 1;

      //loop through every vertical stripe of the sprite on screen
      for(int stripe = drawStartX; stripe < drawEndX; stripe++)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * get_tex_by_name(game, "S").width / spriteWidth) / 256;
        //the conditions in the if are:
        //1) it's in front of camera plane so you don't see things behind you
        //2) it's on the screen (left)
        //3) it's on the screen (right)
        //4) ZBuffer, with perpendicular distance
        if(transformY > 0 && stripe > 0 && stripe < game->resolution.x && transformY < game->z_buffer[stripe])
        for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
        {
          int d = (y - vMoveScreen) * 256 - game->resolution.y * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
          int texY = ((d * get_tex_by_name(game, "S").height) / spriteHeight) / 256;
		 // printf("texX:%d; texY:%d\n", texX, texY);
		  int color = get_pixel_color(get_tex_by_name(game, "S"), texX, texY);
          //int color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
          if((color & 0x00FFFFFF) != 0) buffer_write(game, game->resolution.x - stripe, y, color); //paint pixel if it isn't black, black is the invisible color
		  
        }
      }
	}
	  return (1);
}
