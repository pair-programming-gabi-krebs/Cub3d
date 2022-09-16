/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 04:33:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/16 03:40:41 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	key_release(int key, t_cube *cube)
{
	if (key == A)
		cube->player.walk_direction = 0;
	else if (key == W)
		cube->player.walk_direction = 0;
	else if (key == S)
		cube->player.walk_direction = 0;
	else if (key == D)
		cube->player.walk_direction = 0;
	else if (key == ARROW_LEFT)
		cube->player.turn_direction = 0;
	else if (key == ARROW_RIGHT)
		cube->player.turn_direction = 0;
	return (0);
}
