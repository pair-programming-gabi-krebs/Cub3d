/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horz_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:03:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:59:30 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	store_hit_wall_value(t_cube *cube);

void	find_horz_hits(t_cube *cube, int i)
{
	cube->horz_has_hit_wall = 0;
	cube->next_horz_hit_y = cube->y_intercept;
	cube->next_horz_hit_x = cube->x_intercept;
	while (cube->next_horz_hit_x >= 0 && cube->next_horz_hit_x <= WINDOW_WIDTH \
		&& cube->next_horz_hit_y >= 0 && cube->next_horz_hit_y <= WINDOW_HEIGHT)
	{
		cube->x_check = cube->next_horz_hit_x;
		cube->y_check = cube->next_horz_hit_y;
		if (cube->rays[i].facing_up)
			cube->y_check += -1;
		if (map_has_wall_at(cube->map.map, cube->x_check, cube->y_check))
		{
			store_hit_wall_value(cube);
			break ;
		}
		else
		{
			cube->next_horz_hit_x += cube->x_step;
			cube->next_horz_hit_y += cube->y_step;
		}
	}
}

static void	store_hit_wall_value(t_cube *cube)
{
	cube->horz_hit_x = cube->next_horz_hit_x;
	cube->horz_hit_y = cube->next_horz_hit_y;
	cube->map.horz_wall = \
		cube->map.map[(int)cube->y_check / TILE_SIZE] \
		[(int)cube->x_check / TILE_SIZE];
	cube->horz_has_hit_wall = 1;
	printf("horz_wall line 47: %i\n", cube->map.horz_wall);
}
