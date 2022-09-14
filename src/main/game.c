/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/14 05:16:15 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	render(t_cube *cube);
static void cast_all_rays(t_cube *cube);
static void update_player(t_cube *cube);
static void render_player(t_cube *cube);


void	game(t_cube *cube)
{
	mlx_hook(cube->mlx_win, KEY_PRESS, 1L << 0, key_map, cube);
	mlx_hook(cube->mlx_win, CLICK_X, 0, close_window, cube);
	mlx_loop_hook(cube->mlx_ptr, render, cube);
	mlx_loop(cube->mlx_ptr);	
}

static int	render(t_cube *cube)
{
	update_player(cube);
	render_player(cube);
	return (0);
}

static void update_player(t_cube *cube)
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
			x++;
		}
		y++;
	}	
}


static void render_player(t_cube *cube)
{
	cast_all_rays(cube);
}

static void cast_all_rays(t_cube *cube)
{
	int		column_id;
	double	ray_angle;

	column_id = 0;
	// colocar rotation_angle na struct
	ray_angle = cube->player.rotation_angle - (deg_to_rad(FOV) / 2);
	
}
