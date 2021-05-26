/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:23:15 by antheven          #+#    #+#             */
/*   Updated: 2021/05/26 16:49:49 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

#include "structs.h"

int		init_app(int arg_count, char **arg_values, t_app *application);
int		init_display(t_app *application);
int		init_buffers(t_app *application);
int		init_loader(t_app *app);
int		init_game(t_app *application);

int		load_scene(t_app *app, char *file_path);
int		load_texture(t_app *app, char *tex_name, char *texture_path);
int		load_texture_color(t_app *app, char *tex_name, int color);

int		new_window(t_app *application, int size_x, int size_y, char *win_name);
int		destroy_window(t_display *display, int win_id);
int		destroy_all_windows(t_display *display);
void	fatal(t_app *app, char *reason);

t_image get_tex_by_name(t_cub *game, char *name);
t_image get_tex_by_id(t_cub *game, int id);
unsigned int	get_pixel_color(t_image image, int x, int y);

void	start(t_app *application);
int		render(t_cub *game);
int		raycast(t_cub *game);
int		draw_sprites(t_cub *game);
t_dda	dda(t_cub *game, char **grid, t_point grid_size, t_point loc, t_point ray_dir);
int		display(t_app *application);
int		app_loop(t_app *application);
int		buffer_write(t_cub *game, int x, int y, int color);
int		display_buffer(t_app *app);
void	end(t_app *application);


int		update(t_app *app);
int		update_game(t_cub *game);
int		update_entities(t_cub *game);
int		update_player(t_entity *player);

double	degtorad(double degree);
double	radtodeg(double radians);
t_point	vec_add(t_point vector, double n);
t_point	vec_sub(t_point vector, double n);
t_point	vec_mul(t_point vector, double factor);
t_point	vec_div(t_point vector, double factor);
int		draw_line(t_cub *game, t_point start, t_point end, int color);
int		vert_line(t_cub *game, int x, int start_y, int end_y, int color);

int		kb_init(t_app *application);
int		kb_register(t_app *app, int keycode, int (*func)(t_app*));
void	kb_register_keys(t_app *application);
int		kb_press(int keycode, t_app *app);
int		kb_loop(t_app *app);
int		kb_release(int keycode, t_app *app);

int		mouse_press(int button,int x,int y,t_app *param);
int		mouse_release(int button,int x,int y,t_app *param);
int		mouse_motion(int x,int y,t_app *param);

int		init_win_text(t_app *app);
int		string_put(t_output *o, int n, int s, t_point pos, char *text, char m);
int		string_del(t_output *output, int n);

int		move(t_cub *game, t_entity *entity, int relative_yaw);

#endif