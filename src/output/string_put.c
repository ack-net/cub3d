/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:24:47 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 17:32:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		string_put(t_output *o, int n, int s, t_point pos, char *text, char m)
{
	if (n < 0 || n >= MAX_STRINGS || s < 0 || s >= WIN_COUNT)
		return (0);
	if (o->win_text[n].visible)
		if (o->win_text[n].malloc)
			free(o->win_text[n].text);
	o->win_text[n].location = pos;
	o->win_text[n].display = s;
	o->win_text[n].text = text;
	o->win_text[n].visible = 1;
	o->win_text[n].malloc = m;
	return (1);
}
