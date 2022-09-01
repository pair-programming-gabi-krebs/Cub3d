/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:42:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 23:47:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	load_images(t_cube *cube);
static int	render(t_cube *cube);

void	init_window(t_cube *cube)
{	
	cube->mlx_ptr = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx_ptr, 250, 250, "Cub3D");
	load_images(cube);
	mlx_hook(cube->mlx_win, CLICK_X, 0, close_window, cube);
	mlx_loop_hook(cube->mlx_ptr, render, &cube);
	mlx_loop(cube->mlx_ptr);
}

static void	load_images(t_cube *cube)
{
	cube->player.testeImg = mlx_xpm_file_to_image(cube->mlx_ptr, TESTE_IMG, &(cube->player.img_width), &(cube->player.img_height));
}

static int	render(t_cube *cube)
{
	//mlx_put_image_to_window(cube->map.mlx_ptr, cube->map.mlx_win, cube->player.testeImg, cube->player.pos_x * 64, cube->player.pos_y * 64);
	cube->player.pos_x += 1;
	cube->player.pos_y += 1;
	return (0);
}
