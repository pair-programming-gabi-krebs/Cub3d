/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:33:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/20 04:23:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_press(int key, t_cube *cube)
{
	if (key == ESC || key == QUIT)
		close_window(cube);
	else if (key == A)
		cube->player.walk_direction = -1;
	else if (key == W)
		cube->player.walk_direction = +1;
	else if (key == S)
		cube->player.walk_direction = -1;
	else if (key == D)
		cube->player.walk_direction = +1;
	else if (key == ARROW_LEFT)
		cube->player.turn_direction = -1;
	else if (key == ARROW_RIGHT)
		cube->player.turn_direction = +1;
	if (key == A || key == W || key == S || key == D || key == ARROW_LEFT || key == ARROW_RIGHT)
		cube->player.has_updated = 1;
	return (0);
}
