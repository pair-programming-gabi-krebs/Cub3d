/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:16:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 01:53:06 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	map_width(char **map);
static int	map_height(char **map);

int	map_has_wall_at(char **map, double x_check, double y_check)
{
	int	map_grid_x;
	int	map_grid_y;

	if ((x_check < 0 || x_check > map_width(map) - 1) \
		|| (y_check < 0 || y_check > map_height(map) -1))
		return (0);
	map_grid_x = floor(x_check / TILE_SIZE);
	map_grid_y = floor(y_check / TILE_SIZE);
	// not working
	if (map[map_grid_y][map_grid_x] == '1')
		return (1);
	return (0);
}

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
