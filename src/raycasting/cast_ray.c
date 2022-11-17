/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:05:20 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:07:51 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	cast_ray(t_cube *cube, double ray, int i)
{
	double	ray_angle;

	ray_angle = normalize_angle(ray);
	get_ray_direction(cube, ray, i);
	calculate_horz_steps(cube, ray, i);
	find_horz_hits(cube, i);
	calculate_vert_steps(cube, ray, i);
	find_vert_hits(cube, i);
}
