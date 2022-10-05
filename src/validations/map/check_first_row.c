/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:54:28 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 01:54:57 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_first_row(t_cube *cube)
{
	if (!check_valid_chars_line(cube->map.map[0]))
	{
		printf("parei no first row\n");
		return (0);
	}
	return (1);
}
