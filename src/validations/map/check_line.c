/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:59:43 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/16 20:25:02 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_line(t_cube *cube, int i, char *line)
{
	int	j;

	j = 1;
	while (line[j])
	{
		if (line[j] == ' ')
		{
			if (cube->map.map[i][j - 1] && (!check_valid_char(cube->map.map[i][j - 1])
				|| (cube->map.map[i][j + 1] && !check_valid_char(cube->map.map[i][j + 1]))
				|| (cube->map.map[i + 1] && !check_valid_char(cube->map.map[i + 1][j]))
				|| (i > 0 && (cube->map.map[i - 1] && !check_valid_char(cube->map.map[i - 1][j])))))
				return (0);
		}
		j++;
	}
	return (1);
}
