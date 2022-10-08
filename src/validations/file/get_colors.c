/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:53:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 06:04:44 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

static void	get_color(char **orientation, char *color);

void	get_colors(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->content.content[i])
	{
		if (ft_strnstr(cube->content.content[i], "F", ft_strlen(cube->content.content[i])))
		{
			get_color(&cube->content.floor_color, cube->content.content[i]);
			cube->content.last_color_line = i;
		}
		else if (ft_strnstr(cube->content.content[i], "C", ft_strlen(cube->content.content[i])))
		{
			get_color(&cube->content.ceil_color, cube->content.content[i]);
			cube->content.last_color_line = i;
		}
		i++;
	}
}

static void	get_color(char **orientation, char *color)
{
	char	**color_mapped;

	color_mapped = ft_split(color, ' ');
	*orientation = ft_strdup(color_mapped[1]);
	free_matrix(color_mapped);
}
