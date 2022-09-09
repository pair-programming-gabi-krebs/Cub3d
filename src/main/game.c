/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/08 23:05:27 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	render(t_cube *cube);

void	game(t_cube *cube)
{
	mlx_hook(cube->mlx_win, KEY_PRESS, 1L << 0, key_map, cube);
	mlx_hook(cube->mlx_win, CLICK_X, 0, close_window, cube);
	mlx_loop_hook(cube->mlx_ptr, render, cube);
	mlx_loop(cube->mlx_ptr);	
}

static int	render(t_cube *cube)
{
	put_image_to_window(cube);
	cast_all_rays(cube);
	return (0);
}

static void cast_all_rays(t_cube *cube)
{
	int		column_id;
	double	ray_angle;

	column_id = 0;
	// colocar rotation_angle na struct
	ray_angle = cube->player.rotation_angle - (deg_to_rad(FOV) / 2);
	
}

static void put_image_to_window(t_cube *cube)
{
	int	x;
	int	y;

	y = -1;
	while (cube->map[++y])
	{
		x = -1;
		while (cube->map[y][++x])
		{
			if (cube->map[y][x] == '1')
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.paredeImg, x * SIZE_IMG, y * SIZE_IMG);
			else if (cube->map[y][x] == '0')
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.testeImg, x * SIZE_IMG, y * SIZE_IMG);
			else if (cube->map[y][x] == 'N')
			{
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.personagemImg, x * SIZE_IMG, y * SIZE_IMG);
				cube->player_x = x;
				cube->player_y = y;
			}
		}
	}	
}
