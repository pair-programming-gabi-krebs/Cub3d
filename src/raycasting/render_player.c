/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:50:36 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/16 21:15:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	render_player(t_cube *cube)
{
	mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
	draw_line(cube, 
			cube->player.pos_x * SIZE_IMG,
			cube->player.pos_y * SIZE_IMG, 
			cube->player.pos_x * SIZE_IMG + \
				(cos(cube->player.rotation_angle) * 50),
			cube->player.pos_y * SIZE_IMG + \
				(sin(cube->player.rotation_angle) * 50));
	cast_all_rays(cube);
	return (0);
}
