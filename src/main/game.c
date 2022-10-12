/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/12 02:44:11 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	render(t_cube *cube);
static void cast_all_rays(t_cube *cube);
static void update_player(t_cube *cube);
static void render_player(t_cube *cube);
static int	is_wall(t_cube *cube, double x, double y);
static void render_map(t_cube *cube);


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
	render_map(cube);
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
	
	if (!is_wall(cube, new_pos_x, new_pos_y))
	{
		cube->player.pos_x = new_pos_x;
		cube->player.pos_y = new_pos_y;
	}
	printf("cube->player.pos_x: %f\ncube->player.pos_y: %f\n", cube->player.pos_x, cube->player.pos_y);
}

static void render_player(t_cube *cube)
{
	mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
	draw_line(cube, 
			cube->player.pos_x * SIZE_IMG,
			cube->player.pos_y * SIZE_IMG, 
			cube->player.pos_x * SIZE_IMG + (cos(cube->player.rotation_angle) * 50),
			cube->player.pos_y * SIZE_IMG + (sin(cube->player.rotation_angle) * 50));
	cast_all_rays(cube);
}

static int	is_wall(t_cube *cube, double x, double y)
{
	int x_parse;
	int	y_parse;
	
	if (x < 0 || (x * SIZE_IMG) > WINDOW_WIDTH || y < 0 || (y * SIZE_IMG) > WINDOW_HEIGHT)
		return (1);
	x_parse = floor(x);
	y_parse = floor(y);
	printf("Floor x: %d\nFloor y: %d\n", x_parse, y_parse);
	if (!cube->map.map[y_parse][x_parse] || cube->map.map[y_parse][x_parse] == '1')
	{
		printf("XMEN!\n");
		return (1);
	}
	return (0);
}

static void cast_all_rays(t_cube *cube)
{
	int		i;
	double	ray_angle;

	ray_angle = cube->player.rotation_angle - (deg_to_rad(FOV)/2);
	printf("ray angle: %f\n", ray_angle);
	printf("rotation angle: %f\n", cube->player.rotation_angle);
	i = 0;
	while (i < NUM_RAYS)
	{
		//cast_ray(cube, i);
		ray_angle += deg_to_rad(FOV)/NUM_RAYS;
		printf("ray angle: %f\n", ray_angle);
		printf("rotation angle: %f\n", cube->player.rotation_angle);
		i++;
	}
}

static void render_map(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->map.map[y])
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == '1')
			{
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.paredeImg, x * SIZE_IMG, y * SIZE_IMG);
			}
			x++;
		}
		y++;
	}
}
