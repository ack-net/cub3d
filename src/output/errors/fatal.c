/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 21:15:34 by antheven          #+#    #+#             */
/*   Updated: 2021/03/29 21:15:34 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	fatal(t_app *app, char *reason)
{
	printf("[%s] Fatal error during execution: %s\n",
		ft_strrchr(app->program.arg_values[0], '/') + 1, reason);
	end(app);
	exit(EXIT_FAILURE);
}
