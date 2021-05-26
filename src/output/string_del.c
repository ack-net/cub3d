/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:30:03 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 17:09:45 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		string_del(t_output *output, int n)
{
	if (n < 0 || n >= MAX_STRINGS)
		return (0);
	output->win_text[n].visible = 0;
	output->win_text[n].location.x = 0;
	output->win_text[n].location.y = 0;
	output->win_text[n].display = 0;
	if (output->win_text[n].malloc)
		free(output->win_text[n].text);
	output->win_text[n].malloc = 0;
	output->win_text[n].text = 0;
	return (1);
}
