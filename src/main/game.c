/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 05:01:51 by gcosta-d         ###   ########.fr       */
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
	return (0);
}
