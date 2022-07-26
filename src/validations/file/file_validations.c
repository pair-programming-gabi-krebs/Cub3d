/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:30:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/08 02:10:54 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	file_validations(t_cube *cube, int arguments, char *file)
{
	if (file && arguments == 2)
	{
		path_validation(cube, file);
		content_validations(cube, file);
	}
	else
		ft_exit(cube, WRONG_FILE);
}
