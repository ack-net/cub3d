/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_release.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:14:55 by antheven          #+#    #+#             */
/*   Updated: 2021/04/07 10:52:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		kb_release(int keycode, t_app *app)
{
	app->input.keyboard.key[keycode].keycode = 0;
	return (1);
}