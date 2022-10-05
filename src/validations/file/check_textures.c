/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:45:28 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:45:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_textures(t_cube *cube)
{
	if (cube->content.north_pattern != NULL
		&& cube->content.south_pattern != NULL
		&& cube->content.west_pattern != NULL
		&& cube->content.east_pattern != NULL)
		return (1);
	return (0);
}
