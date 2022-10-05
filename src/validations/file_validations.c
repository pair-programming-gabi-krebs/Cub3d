/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:30:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/24 23:58:13 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void path_validation(char *file);

void	file_validations(t_cube *cube, int arguments, char *file)
{
	if (file && arguments == 2)
	{
		path_validation(file);
		content_validations(cube, file);
	}
	else
		ft_exit(WRONG_FILE);
}

static void path_validation(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (strict_strcmp(dot, ".cub"))
		ft_exit(WRONG_EXTENSIONS);
}
