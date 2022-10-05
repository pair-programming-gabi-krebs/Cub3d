/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:22:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/05 02:39:03 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	get_map(t_cube *cube)
{
	int	line;

	line = get_first_map_line(cube);
	if (line == 0)
		ft_exit(WRONG_MAP);
	copy_map(cube, line);
}
