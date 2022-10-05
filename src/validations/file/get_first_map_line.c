/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_map_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:37:41 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:37:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	get_first_map_line(t_cube *cube)
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
