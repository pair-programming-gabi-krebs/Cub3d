/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:54:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/11/23 01:12:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libs/libft.h"

# define WRONG_FILE "Enter a valid map"
# define WRONG_EXTENSIONS "Enter a valid .cub file"
# define WRONG_CONTENT "Enter a valid content for .cub file"
# define WRONG_MAP "Enter a valid map"
# define WRONG_CHAR "The map must only contain valid chars"
# define WRONG_PLAYER "The map must contain one player"
# define PI 3.14159265
# define TWO_PI 6.28318530
# define MAX_INT 2147483647
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"
# define CLICK_X 17
# define SIZE_IMG 64
# define ESC 65307
# define FOV 60
# define QUIT 113
# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define A 97
# define W 119
# define S 115
# define D 100
# define TILE_SIZE 64
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600
# define NUM_RAYS 300

# define TESTE_IMG "./assets/teste.xpm"
# define PAREDE "./assets/parede.xpm"
# define PERSONAGEM "./assets/personagem.xpm"

typedef struct s_player
{
	void	*testeImg;
	void	*paredeImg;
	void	*personagemImg;
	int		img_width;
	int		img_height;
	double	pos_x;
	double	pos_y;
	double	rotation_angle;
	double	turn_direction;
	double	walk_direction;
	double	move_speed;
	double	rotation_speed;
	int		has_updated;
}	t_player;

typedef struct s_content
{
	char	**content;
	char	*north_pattern;
	char	*south_pattern;
	char	*west_pattern;
	char	*east_pattern;
	char	*floor_color;
	char	*ceil_color;
	int		last_color_line;
	int		total_lines;
}	t_content;

typedef struct s_map
{
	char	**map;
	int		horz_wall;
	int		vert_wall;
}	t_map;

typedef struct s_rays
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		facing_up;
	int		was_hit_vert;
	int		facing_down;
	int		facing_left;
	int		facing_right;
	int		hit_content;
}	t_rays[NUM_RAYS];

typedef struct s_cube
{
	void		*mlx_ptr;
	void		*mlx_win;
	long		horz_x_step;
	long		vert_x_step;
	long		horz_y_step;
	long		vert_y_step;
	long		x_intercept;
	long		y_intercept;
	long		horz_hit_x;
	long		horz_hit_y;
	long		vert_hit_x;
	long		vert_hit_y;
	int			horz_has_hit_wall;
	int			vert_has_hit_wall;
	double		next_horz_hit_y;
	double		next_horz_hit_x;
	double		next_vert_hit_y;
	double		next_vert_hit_x;
	double		x_check;
	double		y_check;
	t_player	player;
	t_content	content;
	t_map		map;
	t_rays		rays;
}	t_cube;

// Validations
void	file_validations(t_cube *cube, int arguments, char *file);
void	content_validations(t_cube *cube, char *file);
void	get_textures(t_cube *cube);
void	get_colors(t_cube *cube);
void	get_map(t_cube *cube);
int		check_map(t_cube *cube);
int		check_first_row(t_cube *cube);
int		check_valid_chars_line(char *s);
int		check_valid_char(char chr);
int		check_last_row(t_cube *cube);
int		map_last_line(t_cube *cube);
int		map_last_line(t_cube *cube);
int		check_body(t_cube *cube);
int		check_around_spaces(t_cube *cube);
int		check_space(t_cube *cube, int i, int j);
void	copy_file(t_cube *cube, char *file);
void	path_validation(t_cube *cube, char *file);
int		get_first_map_line(t_cube *cube);
int		count_lines(t_cube *cube, char *file);
int		open_file(t_cube *cube, char *file);
int		check_border_line(char *line);
int		check_textures(t_cube *cube);
int		check_colors(t_cube *cube);
void	copy_map(t_cube *cube, int line);
void	equalize_map(char **map);
void	strjoin_spaces(char **map, size_t big_str, size_t len, int i);
size_t	biggest_str(char **map);
int		check_line(t_cube *cube, int i, char *line);
void	check_body_chars(t_cube *cube);

// raycasting
int		render(t_cube *cube);
int		render_map(t_cube *cube);
int		render_player(t_cube *cube);
int		update_player(t_cube *cube);
void	cast_all_rays(t_cube *cube);
void	cast_ray(t_cube *cube, double ray, int i);
double	normalize_angle(double angle);
void	get_ray_direction(t_cube *cube, double ray, int i);
void	calculate_horz_steps(t_cube *cube, double ray, int i);
void	calculate_vert_steps(t_cube *cube, double ray, int i);
void	find_horz_hits(t_cube *cube, int i);
void	find_vert_hits(t_cube *cube, int i);
int		map_has_wall_at(char **map, double x_check, double y_check);
void	calculate_distance(t_cube *cube, int i);
double	distance_between_points(t_cube *cube, double hit_x, double hit_y);

// game files
void	init_window(t_cube *cube);
void	setup(t_cube *cube);
int		close_window(t_cube *cube);
void	game(t_cube *cube);
int		key_press(int key, t_cube *cube);
int		key_release(int key, t_cube *cube);

// Utils
void	trim_line(char **str, char *arg);
void	parse_line(char **str);
void	ft_exit(t_cube *cube, char *message);
void	ft_init(t_cube *cube);
int		strict_strcmp(const char *s1, const char *s2);
double	deg_to_rad(double degree);
void	draw_line(t_cube *cube, double begin_x, double begin_y, double end_x, double end_y);
int		ft_is_space(unsigned int i, char *s);
void	free_matrix(char **matrix);
int		is_wall(t_cube *cube, double x, double y);

#endif
