/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:22:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/27 00:14:13 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	get_first_map_line(t_cube *cube);
static void	copy_map(t_cube *cube, int line);

void	get_map(t_cube *cube)
{
	int	line;

	line = get_first_map_line(cube);
	if (line == 0)
		ft_exit(WRONG_MAP);
	copy_map(cube, line);
}

static int	get_first_map_line(t_cube *cube)
{
	int	line;

	line = cube->content.last_color_line + 1;
	while (cube->content.content[line])
	{
		if (ft_strchr(cube->content.content[line], '1'))
			return (line);
		line++;
	}
	return (0);
}

static void	copy_map(t_cube *cube, int line)
{
	int	i;
	
	cube->map.map = malloc(sizeof(char*) * (cube->content.total_lines + 1));
	i = 0;
	while (cube->content.content[line])
	{
		cube->map.map[i] = ft_strdup(cube->content.content[line]);
		i++;
		line--;
	}
	cube->map.map[i] = NULL;
}
