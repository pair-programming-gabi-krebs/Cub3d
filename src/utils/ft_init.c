/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:22:28 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/25 06:40:55 by gcosta-d         ###   ########.fr       */
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
	cube->player.move_speed =  0.02;
	cube->player.rotation_speed = 0.03 * (M_PI / 180);
	cube->player.has_updated = 0;
	// think of a function that returns the screen size
	cube->content.north_pattern = NULL;
	cube->content.south_pattern = NULL;
	cube->content.west_pattern = NULL;
	cube->content.east_pattern = NULL;
}