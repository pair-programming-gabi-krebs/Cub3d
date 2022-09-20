/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:30:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/20 01:54:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void path_validation(char *file);
static int open_file(char *file);

void	file_validations(t_cube *cube, int arguments, char *file)
{
	if (file && arguments == 2)
	{
		path_validation(file);
		content_validations(cube, open_file(file));
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

static int open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_exit(WRONG_FILE);
	return (fd);
}
