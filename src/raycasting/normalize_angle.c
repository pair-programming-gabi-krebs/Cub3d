/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:44:10 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/18 00:21:23 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

double	normalize_angle(double ray)
{
	// TWO_PI, is it M_PI * 2?
	ray = remainder(ray, M_PI * 2);
	if (ray < 0)
	{
		ray = M_PI * 2 + ray;
	}
	return ray;
}
