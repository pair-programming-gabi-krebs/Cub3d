/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:33:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 06:08:19 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	free_textures(t_cube *cube);

void	ft_exit(t_cube *cube, char *message)
{
	free_matrix(cube->map.map);
	free_matrix(cube->content.content);
	free_textures(cube);
	printf("Error\n%s\n", message);
	exit(0);
}

static void	free_textures(t_cube *cube)
{
	free(cube->content.floor_color);
	free(cube->content.ceil_color);
	free(cube->content.north_pattern);
	free(cube->content.south_pattern);
	free(cube->content.east_pattern);
	free(cube->content.west_pattern);
}
