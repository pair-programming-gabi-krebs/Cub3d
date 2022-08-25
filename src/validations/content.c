/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:00:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/24 21:02:09 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	textures(t_cube *cube, char *line);

void	content_validations(t_cube *cube, int fd)
{
	char	*line;	

	line = get_next_line(fd);
	while (line)
	{
		textures(cube, line);
		free(line);
		line = get_next_line(fd);
	}
	
}

static void	textures(t_cube *cube, char *line)
{
	char	**orientation_arr;
	
	if (ft_strlen(line) > 4)
	{
		orientation_arr = ft_split(line, ' ');
		if (!strict_strcmp(orientation_arr[0], NO))
			cube->north_pattern = ft_strdup(orientation_arr[1]);
		else if (!strict_strcmp(orientation_arr[0], SO))
			cube->south_pattern = ft_strdup(orientation_arr[1]);
		else if (!strict_strcmp(orientation_arr[0], WE))
			cube->west_pattern = ft_strdup(orientation_arr[1]);
		else if (!strict_strcmp(orientation_arr[0], EA))
			cube->east_pattern = ft_strdup(orientation_arr[1]);		
	}
}


// NO ./path_to_the_north_texture\n

// NO
// ./path_to_the_north_texture\n
// \0


// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
