/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:30:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/16 23:21:22 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void path_validation(char *file);
static int open_file(char *file);

void	file_validations(t_cube *cube, char *file)
{
	if (file)
    {
    	path_validation(file);
		content_validations(cube, open_file(file));
	}
}

static void path_validation(char *file)
{
        char    *dot;

        dot = ft_strchr(file, '.');
        if (strict_strcmp(dot, ".cub"))
            ft_exit(WRONG_EXTENSIONS);
}

static int open_file(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (!fd)
        ft_exit(WRONG_FILE);
    return (fd);
}
