/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:51:39 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 00:12:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	is_wall(t_cube *cube, double x, double y)
{
	int	x_parse;
	int	y_parse;

	if (x < 0 || (x * SIZE_IMG) > WINDOW_WIDTH || y < 0 || (y * SIZE_IMG) > WINDOW_HEIGHT)
		return (1);
	x_parse = floor(x);
	y_parse = floor(y);
	if (!cube->map.map[y_parse][x_parse] || \
		cube->map.map[y_parse][x_parse] == '1')
		return (1);
	return (0);
}
