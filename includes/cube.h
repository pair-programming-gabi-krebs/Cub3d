/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:54:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/08 23:06:57 by lkrebs-l         ###   ########.fr       */
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
# define KEY_PRESS 2
# define A 97
# define W 119
# define S 115
# define D 100

# define TESTE_IMG "./assets/teste.xpm"
# define PAREDE "./assets/parede.xpm"
# define PERSONAGEM "./assets/personagem.xpm"

typedef struct s_player
{
	void	*testeImg;
	void	*paredeImg;
	void	*personagemImg;
	int		rotation_angle;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
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
	int			player_x;
	int			player_y;
	t_player	player;
}	t_cube;


// Validations
void	file_validations(t_cube *cube, int arguments, char *file);
void	content_validations(t_cube *cube, int fd);

void	init_window(t_cube *cube);
void	setup(t_cube *cube);
int		close_window(t_cube *cube);
void	game(t_cube *cube);
int		key_map(int key, t_cube *cube);

// Utils
void	ft_exit(char *message);
int		strict_strcmp(const char *s1, const char *s2);
double	deg_to_rad(double degree);

#endif