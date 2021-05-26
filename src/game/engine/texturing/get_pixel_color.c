/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:21:16 by antheven          #+#    #+#             */
/*   Updated: 2021/04/29 15:23:50 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

unsigned int	get_pixel_color(t_image image, int x, int y)
{
	int		color;

	color = *(unsigned int*)(image.data + (y%image.height * image.size_line + x%image.width * (image.bits_per_pixel / 8)) % (image.width*image.height*image.bits_per_pixel));
	return (color);
}
