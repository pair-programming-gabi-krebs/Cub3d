/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:45:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/05 02:10:37 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_map(t_cube *cube)
{
	if (check_first_row(cube) 
		&& check_last_row(cube)
		&& check_around_body(cube)
		&& check_around_spaces(cube))
		return (1);
	return (0);
}
