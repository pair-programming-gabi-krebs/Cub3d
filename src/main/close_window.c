/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:52:20 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/20 04:18:01 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	close_window(t_cube *cube)
{
	mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
	mlx_destroy_window(cube->mlx_ptr, cube->mlx_win);
	mlx_destroy_display(cube->mlx_ptr);
	mlx_loop_end(cube->mlx_ptr);
	free(cube->mlx_ptr);
	exit(0);
	return (0);
}
