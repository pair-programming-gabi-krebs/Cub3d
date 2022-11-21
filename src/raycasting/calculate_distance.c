/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:08:10 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 00:57:06 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static double	horz_hit_distance(t_cube *cube);
static double	vert_hit_distance(t_cube *cube);
static void		store_horz_content(t_cube *cube, double horz_hit_distance);
static void		store_vert_content(t_cube *cube, double vert_hit_distance);

void	calculate_distance(t_cube *cube, int i, double ray_angle)
{
	double	horz_hit_distance;
	double	horz_hit_distance;

	horz_hit_distance = horz_hit_distance(cube);
	vert_hit_distance = vert_hit_distance(cube);
	if (vert_hit_distance < horz_hit_distance)
		store_vert_content(cube, vert_hit_distance);
	else
		store_horz_content(cube, horz_hit_distance);
}

static double	horz_hit_distance(t_cube *cube)
{
	double	horz_hit_distance;

	if (cube->horz_has_hit_wall)
	{
		horz_hit_distance = distance_between_points(cube, cube->horz_hit_x, \
			cube->horz_hit_y);
	}
	else
		horz_hit_distance = MAX_INT;
	return (horz_hit_distance);
}

static double	vert_hit_distance(t_cube *cube)
{
	double	vert_hit_distance;

	if (cube->vert_has_hit_wall)
	{
		vert_hit_distance = distance_between_points(cube, cube->vert_hit_x, \
			cube->vert_hit_y);
	}
	else
		vert_hit_distance = MAX_INT;
	return (vert_hit_distance);
}

static void	store_horz_content(t_cube *cube, double horz_hit_distance)
{
	cube->rays[i].distance = horz_hit_distance;
	cube->rays[i].wall_hit_x = horz_hit_x;
	cube->rays[i].wall_hit_y = horz_hit_y;
	cube->rays[i].hit_content = cube->map.horz_wall;
	cube->rays[i].was_hit_vert = 0;
}

static void	store_vert_content(t_cube *cube, double vert_hit_distance)
{
	cube->rays[i].distance = vert_hit_distance;
	cube->rays[i].wall_hit_x = cube->vert_hit_x;
	cube->rays[i].wall_hit_y = cube->vert_hit_y;
	cube->rays[i].hit_content = cube->map.vert_wall;
	cube->rays[i].was_hit_vert = 1;
}
