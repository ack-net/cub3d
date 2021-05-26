/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_press.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:12:51 by antheven          #+#    #+#             */
/*   Updated: 2021/04/27 20:02:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		kb_press(int keycode, t_app *app)
{
	//	printf("kb_press(%d);\n", keycode);
	app->input.keyboard.key[keycode].keycode = 1;
	app->input.keyboard.last_key_pressed = keycode;
	return (1);
}
