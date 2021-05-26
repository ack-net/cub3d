/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:09:49 by antheven          #+#    #+#             */
/*   Updated: 2021/04/23 15:11:50 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

#ifdef __linux__
#define KEY_ESC 65307
#define KEY_LFT 65361
#define KEY_RGT 65363
#define KEY_FWD 65362
#define KEY_BWD 65364
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_Z 122
#define KEY_Q 113
#define KEY_I 105
#define KEY_E 101
#define KEY_SPACE 32
#define KEY_ENTER 65293
#endif

#ifdef __APPLE__
#define KEY_ESC 53
#define KEY_LFT 123
#define KEY_RGT 124
#define KEY_FWD 126
#define KEY_BWD 125
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_Z 122
#define KEY_Q 12
#define KEY_I 34
#define KEY_E 14
#define KEY_SPACE 49
#define KEY_ENTER 6
#endif

#endif