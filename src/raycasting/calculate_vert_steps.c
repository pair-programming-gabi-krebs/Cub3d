/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vert_steps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:07:29 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:10:38 by lkrebs-l         ###   ########.fr       */
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
	cube->x_step = TILE_SIZE;
	if (cube->rays[i].facing_left)
		cube->x_step *= -1;
	cube->y_step = TILE_SIZE / tan(ray);
	if (cube->rays[i].facing_up && cube->x_step > 0)
		cube->y_step *= -1;
	if (cube->rays[i].facing_down && cube->x_step < 0)
		cube->y_step *= -1;
}
