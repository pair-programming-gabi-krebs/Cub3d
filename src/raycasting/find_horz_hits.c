/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horz_hits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:03:14 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 04:45:13 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	store_hit_wall_value(t_cube *cube);

//
static int	map_width(char **map)
{
	return (ft_strlen(map[0]));
}

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}
//

void	find_horz_hits(t_cube *cube, int i)
{
	cube->horz_has_hit_wall = 0;
	cube->next_horz_hit_y = cube->y_intercept;
	cube->next_horz_hit_x = cube->x_intercept;
	printf("i: %i - next_horz_hit_x %f | next_horz_hit_y %f\n\n", i, cube->next_horz_hit_x, cube->next_horz_hit_y);
	while (cube->next_horz_hit_x >= 0 && cube->next_horz_hit_x <= map_width(cube->map.map) - 1\
		&& cube->next_horz_hit_y >= 0 && cube->next_horz_hit_y <= map_height(cube->map.map) - 1)
	{
		cube->x_check = cube->next_horz_hit_x;
		cube->y_check = cube->next_horz_hit_y;
		printf("x_check %f | y_check %f\n\n", cube->x_check, cube->y_check);
		if (cube->rays[i].facing_up)
			cube->y_check -= 1;
		if (map_has_wall_at(cube->map.map, cube->x_check, cube->y_check))
		{
			store_hit_wall_value(cube);
			break ;
		}
		else
		{
			cube->next_horz_hit_x += cube->horz_x_step;
			cube->next_horz_hit_y += cube->horz_y_step;
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
}
