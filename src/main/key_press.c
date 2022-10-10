/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:33:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/24 04:14:43 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_press(int key, t_cube *cube)
{
	if (key == ESC || key == QUIT)
		close_window(cube);
	else if (key == A)
		cube->player.pos_x -= 0.1; //Arrumar andar p/ lado
	else if (key == W)
		cube->player.walk_direction = 1;
	else if (key == S)
		cube->player.walk_direction = -1;
	else if (key == D)
		cube->player.pos_x += 0.1; //Arrumar andar p/ lado
	else if (key == ARROW_LEFT)
		cube->player.rotation_angle -= 0.2;
	else if (key == ARROW_RIGHT)
		cube->player.rotation_angle += 0.2;
	return (0);
}
