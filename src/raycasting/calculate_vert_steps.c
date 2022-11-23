/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vert_steps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:07:29 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 01:05:27 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	calculate_vert_steps(t_cube *cube, double ray, int i)
{
	cube->x_intercept = floor(cube->player.pos_x / TILE_SIZE) * TILE_SIZE;
	if (cube->rays[i].facing_right)
		cube->y_intercept += TILE_SIZE;
	cube->x_intercept = cube->player.pos_y + \
		(cube->x_intercept - cube->player.pos_x) / tan(ray);
	cube->vert_x_step = TILE_SIZE;
	if (cube->rays[i].facing_left)
		cube->vert_x_step *= -1;
	cube->vert_y_step = TILE_SIZE / tan(ray);
	if (cube->rays[i].facing_up && cube->vert_y_step > 0)
		cube->vert_y_step *= -1;
	if (cube->rays[i].facing_down && cube->vert_y_step < 0)
		cube->vert_y_step *= -1;
}
