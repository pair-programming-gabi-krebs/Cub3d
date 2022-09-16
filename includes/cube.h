/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:54:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/16 03:47:29 by gcosta-d         ###   ########.fr       */
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
# define M_PI 3.14159265358979323846
# define WRONG_EXTENSIONS "Enter a valid .cub file"
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
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600

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
}	t_player;
typedef struct s_cube
{
	char		*north_pattern;
	char		*south_pattern;
	char		*west_pattern;
	char		*east_pattern;
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	t_player	player;
}	t_cube;


// Validations
void	file_validations(t_cube *cube, int arguments, char *file);
void	content_validations(t_cube *cube, int fd);

void	init_window(t_cube *cube);
void	setup(t_cube *cube);
int		close_window(t_cube *cube);
void	game(t_cube *cube);
int		key_press(int key, t_cube *cube);
int		key_release(int key, t_cube *cube);

// Utils
void	ft_exit(char *message);
void	ft_init(t_cube *cube);
int		strict_strcmp(const char *s1, const char *s2);
double	deg_to_rad(double degree);

#endif