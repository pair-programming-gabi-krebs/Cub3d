/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:07:39 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:07:54 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int check_around_spaces(t_cube *cube)
{
	int		i;
	int		j;
	

	i = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (!check_space(cube, i , j))
			{
				printf("ok n\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
