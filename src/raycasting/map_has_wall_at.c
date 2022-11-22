/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:16:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 05:33:30 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	map_has_wall_at(char **map, double x_check, double y_check)
{
	int map_grid_x;
	int map_grid_y;
	
	if ((x_check < 0 || x_check > WINDOW_WIDTH) 
	|| (y_check < 0 || y_check > WINDOW_HEIGHT))
		return (1);
	map_grid_x = x_check / TILE_SIZE;
	map_grid_y = y_check / TILE_SIZE;
	if (map[map_grid_y][map_grid_x] == '1')
		return (1);
	return (0);
}
