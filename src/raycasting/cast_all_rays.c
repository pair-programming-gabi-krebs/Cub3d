/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_all_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:53:57 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/23 01:58:05 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	cast_all_rays(t_cube *cube)
{
	int		i;
	double	ray_angle;

	ray_angle = cube->player.rotation_angle - (deg_to_rad(FOV)/2);
	i = 0;
	while (i < NUM_RAYS)
	{
		cast_ray(cube, ray_angle, i);
		draw_line(cube,
			cube->player.pos_x * SIZE_IMG,
			cube->player.pos_y * SIZE_IMG,
			cube->player.pos_x * SIZE_IMG + (cos(ray_angle) * cube->rays[i].distance),
			cube->player.pos_y * SIZE_IMG + (sin(ray_angle) * cube->rays[i].distance));
		ray_angle += deg_to_rad(FOV) / NUM_RAYS;
		i++;
	}
}
