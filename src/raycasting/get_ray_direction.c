/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:45:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 00:37:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	get_ray_direction(t_cube *cube, double ray_angle, int i)
{
	cube->rays[i].facing_up = 0;
	cube->rays[i].facing_down = 0;
	cube->rays[i].facing_right = 0;
	cube->rays[i].facing_left = 0;
	if (ray_angle > 0 && ray_angle < PI)
		cube->rays[i].facing_down = 1;
	else
		cube->rays[i].facing_up = 1;
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		cube->rays[i].facing_right = 1;
	else
		cube->rays[i].facing_left = 1;
}
