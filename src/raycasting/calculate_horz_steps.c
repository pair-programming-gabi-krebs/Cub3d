/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_horz_steps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:07:42 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 04:54:27 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	calculate_horz_steps(t_cube *cube, double ray_angle, int i)
{	
	cube->y_intercept = floor(cube->player.pos_y) * TILE_SIZE;
	if (cube->rays[i].facing_down)
	{
		cube->y_intercept += TILE_SIZE;
	}	
	cube->x_intercept = (cube->player.pos_x * TILE_SIZE) + \
		(cube->y_intercept - (cube->player.pos_y * TILE_SIZE)) / tan(ray_angle);
	cube->horz_y_step = TILE_SIZE;
	if (cube->rays[i].facing_up)
		cube->horz_y_step *= -1;
	cube->horz_x_step = TILE_SIZE / tan(ray_angle);
	if (cube->rays[i].facing_left && cube->horz_x_step > 0)
		cube->horz_x_step *= -1;
	if (cube->rays[i].facing_right && cube->horz_x_step < 0)
		cube->horz_x_step *= -1;
}
