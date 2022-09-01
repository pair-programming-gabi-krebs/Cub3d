/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:33:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 04:58:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	move_player(t_cube *cube, int x, int y);

int	key_map(int key, t_cube *cube)
{
	int	x;
	int	y;

	x = cube->player_x;
	y = cube->player_y;
	if (key == ESC || key == QUIT)
		close_window(cube);
	else if (key == A)
		x--;
	else if (key == W)
		y--;
	else if (key == S)
		y++;
	else if (key == D)
		x++;
	move_player(cube, x, y);
	return (0);
}

static void	move_player(t_cube *cube, int x, int y)
{
	int	old_x;
	int	old_y;

	old_x = cube->player_x;
	old_y = cube->player_y;

	cube->map[old_y][old_x] = '0';
	cube->map[y][x] = 'N';
	cube->player_y = y;
	cube->player_x = x;
	game(cube);
}