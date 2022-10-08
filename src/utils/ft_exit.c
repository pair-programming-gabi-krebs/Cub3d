/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:33:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 02:17:48 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	ft_exit(t_cube *cube, char *message)
{
	free_matrix(cube->map.map);
	free_matrix(cube->content.content);
	printf("Error\n%s\n", message);
	exit(0);
}
