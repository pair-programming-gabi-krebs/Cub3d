/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:43:45 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/10 22:25:58 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	open_file(t_cube *cube, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_exit(cube, WRONG_FILE);
	return (fd);
}
