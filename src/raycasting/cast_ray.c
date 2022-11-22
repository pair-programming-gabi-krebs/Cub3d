/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:20 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:43:06 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	cast_ray(t_cube *cube, double ray, int i)
{
	double	ray_angle;

	ray_angle = normalize_angle(ray);
	get_ray_direction(cube, ray_angle, i);
	calculate_horz_steps(cube, ray_angle, i);
	find_horz_hits(cube, i);
	calculate_vert_steps(cube, ray_angle, i);
	find_vert_hits(cube, i);
	calculate_distance(cube, i);
}
