/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:22:28 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/22 02:49:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_init(t_cube *cube)
{
	cube->player.pos_x = 0;
	cube->player.pos_y = 0;
	cube->player.rotation_angle = deg_to_rad(90);
	cube->player.turn_direction = 0;
	cube->player.walk_direction = 0;
	cube->player.move_speed = 3.0;
	cube->player.rotation_speed = 0.03 * (M_PI / 180);
	cube->player.has_updated = 0;
	// think of a function that returns the screen size
	cube->north_pattern = NULL;
	cube->south_pattern = NULL;
	cube->west_pattern = NULL;
	cube->east_pattern = NULL;
}