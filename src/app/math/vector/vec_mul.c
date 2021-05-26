/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:42:24 by antheven          #+#    #+#             */
/*   Updated: 2021/04/19 17:42:24 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_point	vec_mul(t_point vector, double factor)
{
	vector.x = vector.x * factor;
	vector.y = vector.y * factor;
	return (vector);
}
