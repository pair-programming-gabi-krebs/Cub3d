/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:45:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/05 18:17:28 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_map(t_cube *cube)
{
	if (check_first_row(cube) 
		&& check_last_row(cube)
		&& check_body(cube))
		return (1);
	return (0);
}
