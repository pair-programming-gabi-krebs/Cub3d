/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:42:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/24 02:14:27 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

//static void	load_images(t_cube *cube);
static void	map_mock(t_cube *cube);
//static void init_map(t_cube *cube);
static void init_player(t_cube *cube);

void	init_window(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	map_mock(cube);
	//load_images(cube);
	//init_map(cube);
	init_player(cube);
}

// static void	load_images(t_cube *cube)
// {
// 	cube->player.testeImg = mlx_xpm_file_to_image(cube->mlx_ptr, TESTE_IMG, &(cube->player.img_width), &(cube->player.img_height));
// 	cube->player.paredeImg = mlx_xpm_file_to_image(cube->mlx_ptr, PAREDE, &(cube->player.img_width), &(cube->player.img_height));
// }

static void	map_mock(t_cube *cube)
{
	char worldMap[11][11]=
	{
		{'1','1','1','1','1','1','1','1','1','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','0','0','1','1','1','0','0','0','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','0','0','0','N','0','0','0','0','1','\0'},
		{'1','0','0','0','0','0','0','0','0','1','\0'},
		{'1','1','1','1','1','1','1','1','1','1','\0'},
		{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
	};
	
	cube->map = malloc(sizeof(char*) * 11);
	cube->map[0] = NULL;
	for (int j = 0; j < 11; j++)
		cube->map[j] = ft_strdup(worldMap[j]);
}

static void init_player(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->map[y][0])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] == 'N' || cube->map[y][x] == 'W' || cube->map[y][x] == 'E' || cube->map[y][x] == 'S')
			{
				cube->player.pos_x = x;
				printf("player position x %d", x);
				cube->player.pos_y = y;
				printf("player position y %d", y);
			}
			if (cube->map[y][x] == 'N')
				cube->player.rotation_angle = deg_to_rad(270);
			else if (cube->map[y][x] == 'W')
				cube->player.rotation_angle = deg_to_rad(0);
			else if (cube->map[y][x] == 'E')
				cube->player.rotation_angle = deg_to_rad(180);
			else if (cube->map[y][x] == 'S')
				cube->player.rotation_angle = deg_to_rad(90);
			x++;
		}
		y++;
	}
	draw_line(cube, 
			  cube->player.pos_x * SIZE_IMG,
			  cube->player.pos_y * SIZE_IMG, 
			  cube->player.pos_x * SIZE_IMG + (cos(cube->player.rotation_angle) * 50), 
			  cube->player.pos_y * SIZE_IMG + (sin(cube->player.rotation_angle) * 50));
}

void	draw_line(t_cube *cube, double begin_x, double begin_y, double end_x, double end_y)
{
	double delta_x; // diferença entre o ponto inicial e o final
	double delta_y;
	double pixels_x; // pontos a serem desenhados
	double pixels_y;
	double pixels_qnt; // quantidade de pixels a ser desenhada
	
	delta_x = end_x - begin_x;
	delta_y = end_y - begin_y;
	pixels_qnt = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels_qnt;
	delta_y /= pixels_qnt;
	pixels_x = begin_x;
	pixels_y = begin_y;
	while (pixels_qnt > 0)
	{
		mlx_pixel_put(cube->mlx_ptr, cube->mlx_win, pixels_x, pixels_y, 0xFF0000);
		pixels_x += delta_x;
		pixels_y += delta_y;
		pixels_qnt--;
	}
}
