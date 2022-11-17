/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:10:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/16 20:35:23 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_space(t_cube *cube, int i, int j)
{
	if (cube->map.map[i][j] && check_valid_char(cube->map.map[i][j]))
	{
		if (((cube->map.map[i - 1]) && check_valid_char(cube->map.map[i - 1][j]))
			&& (cube->map.map[i + 1] && check_valid_char(cube->map.map[i + 1][j]))
			&& (cube->map.map[i] && check_valid_char(cube->map.map[i][j - 1]))
			&& (cube->map.map[i] && check_valid_char(cube->map.map[i][j + 1])))
			return (1);
	}
	return (0);
}
