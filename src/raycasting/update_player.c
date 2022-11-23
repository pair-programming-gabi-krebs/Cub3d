/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:49:56 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 01:51:17 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	update_player(t_cube *cube)
{
	double	step;
	double	new_pos_x;
	double	new_pos_y;

	step = cube->player.walk_direction * cube->player.move_speed;
	if (cube->player.rotation_angle < 0)
		cube->player.rotation_angle += 2 * M_PI;
	else if (cube->player.rotation_angle > 2 * M_PI)
		cube->player.rotation_angle -= 2 * M_PI;
	new_pos_x = cube->player.pos_x + cos(cube->player.rotation_angle) * step;
	new_pos_y = cube->player.pos_y + sin(cube->player.rotation_angle) * step;
	if (!is_wall(cube, new_pos_x, new_pos_y))
	{
		cube->player.pos_x = new_pos_x;
		cube->player.pos_y = new_pos_y;
	}
	return (0);
}
