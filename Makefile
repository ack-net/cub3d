# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antheven <antheven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 14:33:05 by antheven          #+#    #+#              #
#    Updated: 2021/05/26 16:50:23 by antheven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	= main.c cub3d.c \
		initialization/app/end.c \
		initialization/app/init_app.c \
		initialization/app/start.c \
		initialization/game/init_game.c \
		initialization/game/init_loader.c \
		initialization/input/kb_init.c \
		initialization/input/kb_register_keys.c \
		initialization/output/win_text.c \
		initialization/display/init_display.c \
		initialization/display/init_buffers.c \
		initialization/display/new_window.c \
		initialization/display/destroy_window.c \
		app/math/degtorad.c \
		app/math/radtodeg.c \
		app/math/vector/vec_add.c \
		app/math/vector/vec_sub.c \
		app/math/vector/vec_mul.c \
		app/math/vector/vec_div.c \
		app/display/display.c \
		app/display/glu/draw_line.c \
		app/display/glu/vert_line.c \
		app/display/buffer/buffer_write.c \
		app/display/buffer/display_buffer.c \
		app/engine/app_loop.c \
		game/loader/load_scene.c \
		game/loader/load_texture.c \
		game/engine/update/player.c \
		game/engine/update/entities.c \
		game/engine/update/update_game.c \
		game/engine/update/update.c \
		game/engine/texturing/get_texture.c \
		game/engine/texturing/get_pixel_color.c \
		game/entity/moving/move.c \
		game/render/dda.c \
		game/render/raycast.c \
		game/render/render.c \
		game/render/draw_sprites.c \
		input/keyboard.c \
		input/kb_press.c \
		input/kb_release.c \
		input/mouse_press.c \
		input/mouse_release.c \
		input/mouse_motion.c \
		output/string_put.c \
		output/string_del.c \
		output/errors/fatal.c
SRCS_FOLDER	= ./src
UNAME_S := $(shell uname -s)
MLX_FOLDER = lib/minilibx-$(UNAME_S)

SRCS		=   $(addprefix $(SRCS_FOLDER)/, $(SRCS_FILES))
NAME		= cub3d
OBJS		= $(SRCS:.c=.o)

INC			= -Iinc -I$(MLX_FOLDER)
LIBS_Linux	= -L$(MLX_FOLDER) -lm -lmlx -lXext -lX11 -lm -lbsd -Llib/libft -lft -Llib -lcolor
LIBS_Darwin	= -lmlx -framework OpenGL -framework AppKit -Llib/libft -lft
CFLAGS		= $(INC) -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = cub3d

all: $(NAME)

$(NAME): mlx libft check_objs
	@printf "\nCompiling...\n"
	@$(CC) -o $(NAME) $(OBJS) $(LIBS_$(UNAME_S)) $(CFLAGS)

check_objs:
	@printf "Checking objects presence\n"
	@$(MAKE) -s $(OBJS)
	@printf "\nDone checking\n"

%.o: %.c
	@printf "\r$< => $@"
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf " - OK%c" 10

clean:
	$(RM) -rf $(OBJS)
	@$(MAKE) -s -C $(MLX_FOLDER) clean

fclean:	clean
	$(RM) -rf $(NAME)
	@$(MAKE) -s -C lib/libft fclean

re:		fclean all

libft:
	@$(MAKE) -C lib/libft

mlx:
	@$(MAKE) -C $(MLX_FOLDER)

bonus:

.PHONY: libft mlx