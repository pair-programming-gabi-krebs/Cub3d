# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 01:36:33 by gcosta-d          #+#    #+#              #
#    Updated: 2022/11/23 00:11:50 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror -g3 

CC = clang

VPATH = src/main src/validations src/utils src/validations/map src/validations/file src/raycasting

FLAGS = -lm -lmlx -lXext -lX11

FILES = main.c \
		strict_strcmp.c \
		ft_exit.c \
		content_validations.c \
		file_validations.c \
		ft_init.c \
		init_window.c \
		close_window.c \
		setup.c \
		game.c \
		key_press.c \
		key_release.c \
		deg_to_rad.c \
		get_textures.c \
		get_colors.c \
		get_map.c \
		ft_is_space.c \
		check_body.c \
		check_around_spaces.c \
		check_first_row.c \
		check_last_row.c \
		check_map.c \
		check_valid_chars_line.c \
		check_valid_char.c \
		check_space.c \
		map_last_line.c \
		trim_line.c \
		copy_file.c \
		copy_map.c \
		get_first_map_line.c \
		path_validation.c \
		check_colors.c \
		check_textures.c \
		count_lines.c \
		open_file.c \
		parse_line.c \
		check_border_line.c \
		equalize_map.c \
		strjoin_spaces.c \
		biggest_str.c \
		check_line.c \
		free_matrix.c \
		check_body_chars.c \
		render.c \
		render_map.c \
		update_player.c \
		render_player.c \
		cast_all_rays.c \
		cast_ray.c \
		is_wall.c \
		calculate_horz_steps.c \
		calculate_vert_steps.c \
		find_horz_hits.c \
		find_vert_hits.c \
		normalize_angle.c \
		get_ray_direction.c \
		map_has_wall_at.c \
		calculate_distance.c \
		distance_between_points.c

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
