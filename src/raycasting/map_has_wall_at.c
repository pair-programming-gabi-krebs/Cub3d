/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_has_wall_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:16:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:21:39 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	map_has_wall_at(char **map, double x_check, double y_check)
{
	if (map[(int)y_check][(int)x_check] == '1')
		return (1);
	return (0);
}
