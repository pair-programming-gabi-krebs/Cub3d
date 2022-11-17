/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:49:01 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:21:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	store_hit_wall_value(t_cube *cube);

void	find_vert_hits(t_cube *cube, int i)
{
	cube->vert_has_hit_wall = 0;
	cube->next_vert_hit_y = cube->y_intercept;
	cube->next_vert_hit_x = cube->x_intercept;
	while (cube->next_vert_hit_x >= 0 && cube->next_vert_hit_x <= WINDOW_WIDTH \
		&& cube->next_vert_hit_y >= 0 && cube->next_vert_hit_y <= WINDOW_HEIGHT)
	{
		cube->x_check = cube->next_vert_hit_x;
		if (cube->rays[i].facing_left)
			cube->x_check += -1;
		cube->y_check = cube->next_vert_hit_y;
		if (cube->rays[i].facing_up)
			cube->y_check += -1;
		if (map_has_wall_at(cube->map.map, cube->x_check, cube->y_check))
		{
			store_hit_wall_value(cube);
			break ;
		}
		else
		{
			cube->next_vert_hit_x += cube->x_step;
			cube->next_vert_hit_y += cube->y_step;
		}
	}
}

static void	store_hit_wall_value(t_cube *cube)
{
	cube->vert_hit_x = cube->next_vert_hit_x;
	cube->vert_hit_y = cube->next_vert_hit_y;
	cube->map.vert_wall = \
		cube->map.map[(int)floor(cube->y_check / TILE_SIZE)] \
		[(int)floor(cube->x_check / TILE_SIZE)];
	cube->vert_has_hit_wall = 1;
}
