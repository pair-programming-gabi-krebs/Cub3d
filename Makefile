# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 01:36:33 by gcosta-d          #+#    #+#              #
#    Updated: 2022/08/25 02:25:27 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g3 

CC = clang

VPATH = src/main src/map_validations src/utils

FLAGS = -lmlx -lXext -lX11

FILES = main.c \
		file_validations.c \
		strict_strcmp.c \
		ft_exit.c \
		init_window.c \
		content.c \
		file.c \
		ft_init.c

OBJ_PATH = ./objs/

OBJS = $(FILES:%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(MAKE) -C ./libraries
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) ./libraries/libft.a -o $(NAME)

$(OBJ_PATH):
	mkdir -p objs

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(OBJ_PATH)
	rm -rf $(NAME)

re: fclean all