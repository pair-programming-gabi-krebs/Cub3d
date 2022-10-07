/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:06:49 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/08 02:00:22 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_body(t_cube *cube)
{
	int		i;
	char	*line;

	equalize_map(cube->map.map);
	i = 0;
	while (cube->map.map[i])
	{
		line = ft_strdup(cube->map.map[i]);
		parse_line(&line);
		if (check_border_line(line) || !check_line(cube, i, cube->map.map[i]))
			return (0);
		free(line);
		i++;
	}
	return (1);
}
