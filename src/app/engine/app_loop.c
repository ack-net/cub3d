/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:13:58 by antheven          #+#    #+#             */
/*   Updated: 2021/04/27 20:03:03 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		app_loop(t_app *application)
{
	if (!application->run)
		return (0);
	//printf("Loop.\n");
	update(application);
	display(application);
	return (1);
}
