/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:44:56 by antheven          #+#    #+#             */
/*   Updated: 2021/04/19 17:44:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_point	vec_div(t_point vector, double factor)
{
	vector.x /= factor;
	vector.y /= factor;
	return (vector);
}
