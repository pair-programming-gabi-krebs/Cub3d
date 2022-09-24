/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/24 02:43:45 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	render(t_cube *cube);
//static void cast_all_rays(t_cube *cube);
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
	//render_player(cube);
	return (0);
}

static void update_player(t_cube *cube)
{
	double	step;
	double	new_pos_x;
	double	new_pos_y;

	step = cube->player.walk_direction * cube->player.move_speed;
	//cube->player.rotation_angle += cube->player.turn_direction * cube->player.rotation_speed;
	if (cube->player.rotation_angle < 0)
		cube->player.rotation_angle += 2 * M_PI;
	else if (cube->player.rotation_angle > 2 * M_PI)
		cube->player.rotation_angle -= 2 * M_PI;
	printf("cube->player.rotation_angle: %f\n", cube->player.rotation_angle);

	new_pos_x = cube->player.pos_x + cos(cube->player.rotation_angle) * step;
	new_pos_y = cube->player.pos_y + sin(cube->player.rotation_angle) * step;
	
	cube->player.pos_x = new_pos_x;
	cube->player.pos_y = new_pos_y;
	printf("cube->player.pos_x: %f\ncube->player.pos_y: %f\n", cube->player.pos_x, cube->player.pos_y);
	// todo: wall colision
	render_player(cube);
}

static void render_player(t_cube *cube)
{
	if (cube->player.has_updated)
	{
		mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
		draw_line(cube, 
				cube->player.pos_x * SIZE_IMG,
				cube->player.pos_y * SIZE_IMG, 
				cube->player.pos_x * SIZE_IMG + (cos(cube->player.rotation_angle) * 50),
				cube->player.pos_y * SIZE_IMG + (sin(cube->player.rotation_angle) * 50));
		cube->player.has_updated = 1;
	}
	//cast_all_rays(cube);
}

// static void cast_all_rays(t_cube *cube)
// {
// 	int		column_id;
// 	double	ray_angle;

// 	column_id = 0;
// 	// colocar rotation_angle na struct
// 	ray_angle = cube->player.rotation_angle - (deg_to_rad(FOV) / 2);
// }
