/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 06:43:08 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 06:06:07 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

static void	get_texture(char **orientation, char *texture);

void	get_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->content.content[i])
	{
		if (ft_strnstr(cube->content.content[i], "NO", ft_strlen(cube->content.content[i])))
			get_texture(&cube->content.north_pattern, cube->content.content[i]);
		else if (ft_strnstr(cube->content.content[i], "SO", ft_strlen(cube->content.content[i])))
			get_texture(&cube->content.south_pattern, cube->content.content[i]);
		else if (ft_strnstr(cube->content.content[i], "EA", ft_strlen(cube->content.content[i])))
			get_texture(&cube->content.east_pattern, cube->content.content[i]);
		else if (ft_strnstr(cube->content.content[i], "WE", ft_strlen(cube->content.content[i])))
			get_texture(&cube->content.west_pattern, cube->content.content[i]);
		i++;
	}
	//printf("NO %s", cube->content.north_pattern);
	//printf("SO %s", cube->content.south_pattern);
	//printf("EA %s", cube->content.east_pattern);
	//printf("WE %s", cube->content.west_pattern);
}

static void	get_texture(char **orientation, char *texture)
{
	char	**texture_mapped;

	texture_mapped = ft_split(texture, ' ');
	*orientation = ft_strdup(texture_mapped[1]);
	free_matrix(texture_mapped);
}
