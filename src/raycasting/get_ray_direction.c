/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:45:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:20:27 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	get_ray_direction(t_cube *cube, double ray, int i)
{
	cube->rays[i].facing_up = 0;
	cube->rays[i].facing_down = 0;
	cube->rays[i].facing_right = 0;
	cube->rays[i].facing_left = 0;
	if (ray > M_PI && ray < 2 * M_PI)
		cube->rays[i].facing_up = 1;
	else
		cube->rays[i].facing_down = 1;
	if (ray > M_PI / 2 && ray < (3 * M_PI) / 2)
		cube->rays[i].facing_left = 1;
	else
		cube->rays[i].facing_right = 1;
}
