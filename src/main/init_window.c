/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:42:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/24 22:46:35 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	init_window(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx_ptr, 250, 250, "Cub3D");
	mlx_loop(cube->mlx_ptr);
}
