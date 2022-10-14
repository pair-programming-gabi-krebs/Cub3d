/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:00:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/14 04:58:49 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	content_validations(t_cube *cube, char *file)
{
	copy_file(cube, file);
	get_textures(cube);
	get_colors(cube);
	if (!check_textures(cube) && !check_colors(cube))
		ft_exit(cube, WRONG_CONTENT);
	get_map(cube);
	if (!check_map(cube))
		ft_exit(cube, WRONG_MAP);
}
