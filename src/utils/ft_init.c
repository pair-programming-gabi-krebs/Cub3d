/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:22:28 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/17 00:08:54 by gcosta-d         ###   ########.fr       */
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