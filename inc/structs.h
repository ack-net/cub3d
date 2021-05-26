/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:24:54 by antheven          #+#    #+#             */
/*   Updated: 2021/05/17 14:37:09 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef	struct	s_program
{
	int			arg_count;
	char		**arg_values;
}				t_program;

typedef	struct	s_scene_validation
{
	char		is_valid;
	char		*name;
	char		**values;
}				t_scene_validation;

typedef	struct	s_hook
{
	int			hook_level;
	int			hook_mask;
	int			(*funct_ptr)();
	void		*param;
}				t_hook;

typedef	struct	s_point
{
	double			x;
	double			y;
}				t_point;

typedef	struct	s_location
{
	double			x;
	double			y;
	double			z;
}				t_location;

typedef	struct	s_hook_list
{
	char		*hook_name;
	t_hook		hook;
}				t_hook_list;

typedef	struct	s_window
{
	char		*win_name;
	void		*win_ptr;
	t_hook_list	hooks;
}				t_window;

typedef	struct	s_display
{
	void		*ptr;
	t_window	windows[WIN_COUNT];
	char		win_lock[WIN_COUNT];
	int			win_count;
}				t_display;

typedef	struct	s_key
{
	int			keycode;
	int			(*func)(void*);
}				t_key;

typedef	struct	s_keyboard
{
	t_key		key[65535];
	int			key_loc[65535];
	int			n_keys;
	int			last_key_pressed;
}				t_keyboard;

typedef	struct	s_mouse
{
	int			last_btn;
	t_point		loc; 
	t_point		dist;
}				t_mouse;

typedef	struct	s_input
{
	t_keyboard	keyboard;
	t_mouse		mouse;
}				t_input;

typedef	struct	s_win_text
{
	char		*text;
	int			display;
	char		visible;
	char		malloc;
	t_point		location;
}				t_win_text;

typedef	struct	s_output
{
	t_win_text	win_text[MAX_STRINGS];
}				t_output;

typedef	struct	s_image
{
	void		*ptr;
	char		*name;
	char		*type;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	int			color;
}				t_image;

typedef	struct	s_tex_list
{
	t_image		texture[N_TEXTURES];
	char		tex_lock[N_TEXTURES];
	int			n_tex;
}				t_tex_list;

typedef	struct	s_rotation
{
	double			yaw;
	double			pitch;
	double			roll;
	double			fov;
	char			type;
}				t_rotation;

typedef	struct	s_world
{
	char		name[15];
	char		**grid;
	t_point		size;
}				t_world;

typedef	struct	s_world_l
{
	char		id;
	t_world		*obj;
}				t_world_l;

typedef	struct	s_jmp_prc
{
	char		is_jumping;
	char		state;
	double		*z_offset;
}				t_jmp_prc;

typedef	struct	s_process
{
	t_jmp_prc	jump;
}				t_process;

typedef	struct	s_entity
{
	int			type;
	char		name[16];
	int			is_alive;
	t_point		position;
	t_location	location;
	t_point		velocity;
	t_world_l	world;
	t_rotation	rotation;
	t_process	process;
	double		neightest_wal_dist;
}				t_entity;

typedef	struct	s_minimap
{
	char		ratio;
}				t_minimap;

typedef	struct	s_dda
{
	t_point		start;
	t_point		end;
	double		distance;
	char		side;
	char		facing;
}				t_dda;

typedef	struct	s_cub
{
	t_tex_list	textures;
	t_point		resolution;
	t_image		buffers[N_BUFFERS];
	t_entity	entity[MAX_ENTITIES];
	t_world		world[1];
	t_minimap	minimap;
	int			n_buffers;
	int			c_buffer;
	double		*z_buffer;
	double			vars[10];
}				t_cub;

typedef	struct	s_app
{
	t_program	program;
	t_display	display;
	t_input		input;
	t_output	output;
	t_cub		game;
	char		run;
}				t_app;

#endif