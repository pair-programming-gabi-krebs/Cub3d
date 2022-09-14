/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:42:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/14 05:21:04 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	load_images(t_cube *cube);
static void	map_mock(t_cube *cube);
static void init_map(t_cube *cube);
static void init_player(t_cube *cube);

void	init_window(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	map_mock(cube);
	load_images(cube);
	init_map(cube);
	init_player(cube);
}

static void	load_images(t_cube *cube)
{
	cube->player.testeImg = mlx_xpm_file_to_image(cube->mlx_ptr, TESTE_IMG, &(cube->player.img_width), &(cube->player.img_height));
	cube->player.paredeImg = mlx_xpm_file_to_image(cube->mlx_ptr, PAREDE, &(cube->player.img_width), &(cube->player.img_height));
}

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

static void init_map(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->map[y][0])
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (cube->map[y][x] == '1')
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.paredeImg, x * SIZE_IMG, y * SIZE_IMG);
			else if (cube->map[y][x] == '0')
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.testeImg, x * SIZE_IMG, y * SIZE_IMG);
			x++;
		}
		y++;
	}	
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
				cube->player.pos_y = y;
			}
			if (cube->map[y][x] == 'N')
				cube->player.rotation_angle = deg_to_rad(90);
			else if (cube->map[y][x] == 'W')
				cube->player.rotation_angle = deg_to_rad(180);
			else if (cube->map[y][x] == 'E')
				cube->player.rotation_angle = deg_to_rad(0);
			else if (cube->map[y][x] == 'S')
				cube->player.rotation_angle = deg_to_rad(270);
			x++;
		}
		y++;
	}
	mlx_pixel_put(cube->mlx_ptr, cube->mlx_win, (cube->player.pos_x * SIZE_IMG) + (SIZE_IMG / 2), (cube->player.pos_y * SIZE_IMG) + (SIZE_IMG / 2), 0xFF0000);
}
