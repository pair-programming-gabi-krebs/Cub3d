/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:48:17 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/14 04:49:14 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	render_map(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->map.map[y])
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == '1')
			{
				mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->player.paredeImg, x * SIZE_IMG, y * SIZE_IMG);
			}
			x++;
		}
		y++;
	}
}
