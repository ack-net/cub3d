/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:38:02 by antheven          #+#    #+#             */
/*   Updated: 2020/10/27 14:43:35 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef	int		t_mask;
typedef	int		t_rgba;

typedef		struct	s_rgba_color
{
	t_mask			red;
	t_mask			green;
	t_mask			blue;
	t_mask			alpha;
	t_rgba			color;
}					t_color;

typedef		struct	s_color
{
	t_mask			(*get_red)(t_color);
	t_mask			(*get_green)(t_color);
	t_mask			(*get_blue)(t_color);
	t_mask			(*get_alpha)(t_color);
	t_rgba			(*get_color)(t_color);
	t_color			(*add_shade)(double, t_color);
	t_color			(*get_opposite)(t_color);
	t_color	(*new_rgb)(int, int, int);
	t_color	(*new_rgba)(int, int, int, int);
}					t_colorer;

t_colorer			colorer_init(void);
t_mask				get_red(t_color color);
t_mask				get_green(t_color color);
t_mask				get_blue(t_color color);
t_mask				get_alpha(t_color color);
t_rgba				get_color(t_color color);
t_color				add_shade(double distance, t_color color);
t_color				get_opposite(t_color color);
t_color				new_rgb(t_mask r, t_mask g, t_mask b);
t_color				new_rgba(t_mask r, t_mask g, t_mask b, t_mask a);
#endif
