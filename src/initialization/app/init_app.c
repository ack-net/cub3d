/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_app.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:33:53 by antheven          #+#    #+#             */
/*   Updated: 2021/04/22 16:34:38 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		init_app(int arg_count, char **arg_values, t_app *application)
{
	application->program.arg_count = arg_count;
	application->program.arg_values = arg_values;
	if (!init_win_text(application))
		return (0);
	return (1);
}
