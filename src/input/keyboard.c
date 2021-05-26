/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:13:44 by antheven          #+#    #+#             */
/*   Updated: 2021/04/29 16:07:16 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		kb_process(t_app *app, int keycode)
{
	//ft_putstr_fd("[", 1);
	//ft_putchar_fd(keycode, 1);
	//ft_putstr_fd("]", 1);
	//app->input.keyboard.key[keycode].keycode = 0;
	return (app->input.keyboard.key[keycode].func(app));
}

int		kb_register(t_app *app, int keycode, int (*func)(t_app*))
{
	printf("Registering key for keyboard %c (%i) at [%d]\n", ft_isprint(keycode)?keycode : '.', keycode, app->input.keyboard.n_keys);
	app->input.keyboard.key_loc[app->input.keyboard.n_keys] = keycode;
	app->input.keyboard.key[keycode].func = (int (*)(void*))func;
	app->input.keyboard.n_keys++;
	return (1);
}

int		kb_loop(t_app *app)
{
	int		i;

	i = 0;
	//	printf("kbloop\n");
	while (i < app->input.keyboard.n_keys)
		if (app->input.keyboard.key[app->input.keyboard.key_loc[i++]].keycode)
			kb_process(app, app->input.keyboard.key_loc[i - 1]);
	return (1);
}
