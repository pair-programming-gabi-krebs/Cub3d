/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:00:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 02:10:19 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

//static void	textures(t_cube *cube, char *line);
//static void	check_content(cube, line);

void	content_validations(t_cube *cube, char *file)
{
	copy_file(cube, file);
	get_textures(cube);
	get_colors(cube);
	if (!check_textures(cube) && !check_colors(cube))
		ft_exit(cube, WRONG_CONTENT);
	get_map(cube);
	if (!check_map(cube))
		ft_exit(cube, WRONG_MAP);
}


// NO ./path_to_the_north_texture\n

// NO
// ./path_to_the_north_texture\n
// \0


// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
