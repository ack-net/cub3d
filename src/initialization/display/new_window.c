/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:40:53 by antheven          #+#    #+#             */
/*   Updated: 2021/04/27 20:10:02 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int		alloc_window(t_display *display)
{
	int		wid;

	wid = 0;
	while (display->win_lock[wid] && wid < WIN_COUNT)
		wid++;
	if (wid == WIN_COUNT)
		return (-1);
	display->win_lock[wid] = 1;
	printf("Allocating for display at %p, id:%d\n", display->ptr, wid);
	return (wid);
}

int		new_window(t_app *application, int size_x, int size_y, char *win_name)
{
	void		*win_ptr;
	t_display	*display;
	int			wid;

	display = &application->display;
	wid = alloc_window(display);
	if (wid == -1)
		return (wid);
	display->windows[wid].win_name = ft_strdup(win_name);
	win_ptr = mlx_new_window(display->ptr, size_x, size_y, win_name);
	printf("New window at %p, x:%d, Y:%d\n", win_ptr, size_x, size_y);
	mlx_hook(win_ptr, 2, 1L<<0, kb_press, application);
	mlx_hook(win_ptr, 3, 1L<<1, kb_release, application);
	mlx_hook(win_ptr, 4, 1L<<2, mouse_press, application);
	mlx_hook(win_ptr, 5, 1L<<3, mouse_release, application);
	mlx_hook(win_ptr, 6, 1L<<6, mouse_motion, application);
    //mlx_hook(win_ptr, 17, 0L, end, application);
	display->windows[wid].win_ptr = win_ptr;
	return (wid);
}
