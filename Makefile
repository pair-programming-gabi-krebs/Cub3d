# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 01:36:33 by gcosta-d          #+#    #+#              #
#    Updated: 2022/09/25 07:15:12 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g3 

CC = clang

VPATH = src/main src/validations src/utils

FLAGS = -lm -lmlx -lXext -lX11

FILES = main.c \
		strict_strcmp.c \
		ft_exit.c \
		content.c \
		file.c \
		ft_init.c \
		init_window.c \
		close_window.c \
		setup.c \
		game.c \
		key_press.c \
		key_release.c \
		deg_to_rad.c \
		get_textures.c \
		ft_is_space.c

OBJ_PATH = ./objs/

OBJS = $(FILES:%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(MAKE) -C ./libs
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) ./libs/libft.a -o $(NAME)

$(OBJ_PATH):
	mkdir -p objs

clean:
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libs fclean
	rm -rf $(OBJ_PATH)
	rm -rf $(NAME)

re: fclean all