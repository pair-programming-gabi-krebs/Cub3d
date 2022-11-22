/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:44:10 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/22 04:19:04 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

double	normalize_angle(double ray)
{
	ray = remainder(ray, M_PI * 2);
	if (ray < 0)
		ray = M_PI * 2 + ray;
	return (ray);
}
