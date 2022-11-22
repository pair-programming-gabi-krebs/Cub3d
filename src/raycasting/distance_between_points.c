/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:20:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:44:51 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

double	distance_between_points(t_cube *cube, double hit_x, double hit_y)
{
	double	pos_x;
	double	pos_y;
	double	calc_pos;
	double	calc_hits;

	pos_x = cube->player.pos_x;
	pos_y = cube->player.pos_y;
	calc_pos = ((hit_x - pos_x) * (hit_x - pos_x));
	calc_hits = ((hit_y - pos_y) * (hit_y - pos_y));
	return (sqrt(calc_pos + calc_hits));
}
