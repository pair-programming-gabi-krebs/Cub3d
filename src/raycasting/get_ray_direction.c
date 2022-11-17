/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:45:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:06:35 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	get_ray_direction(t_cube *cube, double ray, int i)
{
	cube->rays[i].facing_up = 0;
	cube->rays[i].facing_down = 0;
	cube->rays[i].facing_right = 0;
	cube->rays[i].facing_left = 0;
	// Ray facing up
	if (ray > M_PI && ray < 2 * M_PI) {
		cube->rays[i].facing_up = 1;
		printf("I'm facing up\n");
	}
	else {
		cube->rays[i].facing_down = 1;
		printf("I'm facing down\n");
	}

	// Ray facing left
	if (ray > M_PI/2 && ray < (3 * M_PI)/2) {
		cube->rays[i].facing_left = 1;
		printf("I'm facing left\n");
	}
	else {
		cube->rays[i].facing_right = 1;
		printf("I'm facing right\n");
	}
	
}
