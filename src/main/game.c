/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:11:52 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/11/16 20:53:00 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	game(t_cube *cube)
{
	mlx_hook(cube->mlx_win, KEY_PRESSED, 1L << 0, key_press, cube);
	mlx_hook(cube->mlx_win, KEY_RELEASED, 1L << 1, key_release, cube);
	mlx_hook(cube->mlx_win, CLICK_X, 0, close_window, cube);
	mlx_loop_hook(cube->mlx_ptr, render, cube);
	mlx_loop(cube->mlx_ptr);
}
