/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:34:17 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 14:10:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		destroy_all_windows(t_display *display)
{
	int		i;
	char	no_err;

	i = 0;
	no_err = 1;
	while (i < display->win_count)
		if (!destroy_window(display, i++))
			no_err = 0;
	return (no_err);
}

int		destroy_window(t_display *display, int win_id)
{
	if (!display->win_lock[win_id])
		return (0);
	printf("Destroying window %d at %p\n", win_id, display->windows[win_id].win_ptr);
	mlx_destroy_window(display->ptr, display->windows[win_id].win_ptr);
	free(display->windows[win_id].win_name);
	// !! Manque a gerer les hooks
	display->win_lock[win_id] = 0;
	return (1);
}