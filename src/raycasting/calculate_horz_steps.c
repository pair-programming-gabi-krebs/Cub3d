/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_horz_steps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:07:42 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 00:55:31 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	calculate_horz_steps(t_cube *cube, double ray, int i)
{
	cube->y_intercept = floor(cube->player.pos_y / TILE_SIZE) * TILE_SIZE;
	if (cube->rays[i].facing_down)
		cube->y_intercept += TILE_SIZE;
	cube->x_intercept = cube->player.pos_x + \
		(cube->y_intercept - cube->player.pos_y) / tan(ray);
	cube->y_step = TILE_SIZE;
	if (cube->rays[i].facing_up)
		cube->y_step *= -1;
	cube->x_step = TILE_SIZE / tan(ray);
	if (cube->rays[i].facing_left && cube->x_step > 0)
		cube->x_step *= -1;
	if (cube->rays[i].facing_left && cube->x_step < 0)
		cube->x_step *= -1;
}
