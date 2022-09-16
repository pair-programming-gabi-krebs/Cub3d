/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/16 03:44:25 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	render(t_cube *cube);
static void cast_all_rays(t_cube *cube);
static void update_player(t_cube *cube);
static void render_player(t_cube *cube);


void	game(t_cube *cube)
{
	mlx_hook(cube->mlx_win, KEY_PRESSED, 1L << 0, key_press, cube);
	mlx_hook(cube->mlx_win, KEY_RELEASED, 1L << 1, key_release, cube);
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
	printf("Walk dir: %f\n", cube->player.walk_direction);
	printf("Turn dir: %f\n", cube->player.turn_direction);
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
