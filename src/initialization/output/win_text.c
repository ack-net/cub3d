/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:22:37 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 17:12:03 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		init_win_text(t_app *app)
{
	int		i;

	i = 0;
	while (i < MAX_STRINGS)
	{
		app->output.win_text[i].location.x = 0;
		app->output.win_text[i].location.y = 0;
		app->output.win_text[i].display = 0;
		app->output.win_text[i].visible = 0;
		app->output.win_text[i].malloc = 0;
		app->output.win_text[i].text = 0;
		i++;
	}
	return (1);
}
