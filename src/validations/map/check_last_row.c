/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:02:58 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:03:25 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_last_row(t_cube *cube)
{
	if (!check_valid_chars_line(cube->map.map[map_last_line(cube)]))
	{
		printf("parei no last row\n");
		return (0);
	}
	return (1);
}
