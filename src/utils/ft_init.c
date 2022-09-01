/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:22:28 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/02 00:00:30 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_init(t_cube *cube)
{
	cube->north_pattern = NULL;
	cube->south_pattern = NULL;
	cube->west_pattern = NULL;
	cube->east_pattern = NULL;
}
