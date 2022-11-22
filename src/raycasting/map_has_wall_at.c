/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:16:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:55:20 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	map_has_wall_at(char **map, double x_check, double y_check)
{
	if (map[(int)y_check / TILE_SIZE][(int)x_check / TILE_SIZE] == '1')
	{
		printf("é um: map[%i][%i] = %c\n", ((int)y_check / TILE_SIZE), ((int)x_check / TILE_SIZE), map[(int)y_check / TILE_SIZE][(int)x_check / TILE_SIZE]);
		return (1);
	}
	return (0);
}
