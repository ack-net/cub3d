/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:37:10 by antheven          #+#    #+#             */
/*   Updated: 2021/05/18 14:43:01 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		kb_init(t_app *application)
{
	int		i;

	application->input.keyboard.n_keys = 0;
	application->input.keyboard.last_key_pressed = 0;
	i = 0;
	while (i < 65535)
	{
		application->input.keyboard.key_loc[i] = 0;
		application->input.keyboard.key[i++].keycode = 0;
	}
	kb_register_keys(application);
	return (1);
}
