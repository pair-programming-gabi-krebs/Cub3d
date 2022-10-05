/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:46:10 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:46:36 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_colors(t_cube *cube)
{
	if (cube->content.floor_color != NULL
		&& cube->content.ceil_color != NULL)
		return (1);
	return (0);
}
